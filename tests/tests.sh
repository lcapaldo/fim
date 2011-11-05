# namerule

rm -f test_namerule && g++ -I.. test_namerule.cpp ../namerule.cpp ../globrule.cpp ../rule.cpp -o test_namerule && ./test_namerule

if [ $? -ne 0 ]; then echo "Error"; else echo "Yay"; fi

rm -f test_dirrule && g++ -g -I.. test_dirrule.cpp ../rule.cpp -o test_dirrule && ./test_dirrule

err=$?
if [ $err -ne 0 ]; then echo "Error $err"; else echo "Yay"; fi

rm -f test_anyrule && g++ -g -I.. test_anyrule.cpp ../namerule.cpp ../globrule.cpp ../rule.cpp ../anyrule.cpp -o test_anyrule && ./test_anyrule

err=$?
if [ $err -ne 0 ]; then echo "Error $err"; else echo "Yay"; fi

rm -f test_vacousrule && g++ -g -I.. test_vacousrule.cpp ../rule.cpp -o test_vacousrule && ./test_vacousrule

err=$?
if [ $err -ne 0 ]; then echo "Error $err"; else echo "Yay"; fi

