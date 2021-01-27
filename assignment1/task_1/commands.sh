wc -l ../data/data.dat
grep -c 'dalor\|dolor' ../data/data.dat
wc -w ../data/data.dat
grep ^mol ../data/data.dat | wc -l
ls ../data/test_folder | grep -c '.txt\b'