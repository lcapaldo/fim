# namerule

rm -f test_namerule && g++ -I.. test_namerule.cpp ../namerule.cpp -o test_namerule && ./test_namerule

if [[ $? != 0 ]]; then echo "Error"; else echo "Yay"; fi

