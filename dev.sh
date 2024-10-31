#!/bin/bash


function get_hash() {
  crypto_hash=sha256sum
  files=();
  found=$(find . -type f -not -path './.git*');
  for file in $found; do
    if ! git check-ignore -q $file ; then
      files+=( $file );
    fi;
  done;
  hashes="";
  for file in "${files[@]}" ; do 
    file_hash="$($crypto_hash $file)";
    hashes="${hashes} ${file_hash}"
  done;
  echo $hashes | $crypto_hash;
}

function mainloop() {
  old_hash="";
  timeout=2;
  while true; do
    new_hash=$(get_hash);
    if [ "$new_hash" != "$old_hash" ]; then 
      echo "Recompilng...";
      ./compile.sh > /dev/null;
    fi;
    old_hash=$new_hash;
    sleep $timeout;
  done;
}

mainloop;
