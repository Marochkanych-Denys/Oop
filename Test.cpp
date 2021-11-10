#define BOOST_TEST_MODULE mytests
#include <boost/test/included/unit_test.hpp>
#include "Doque.h"


BOOST_AUTO_TEST_SUITE(TestCase)

//=============================================================================================================
BOOST_AUTO_TEST_CASE(Milk_Product_Add)
{
    Deque* container = new Deque();
    BOOST_CHECK(!container->show_all()); // При створенні контейнер має бути пустим
    Milk* milk = new Milk("tes1", "tes1", 11.11, 11.11, "test1");
    container->add_element(milk);
    BOOST_CHECK(container->show_all()); // В контенері повинна бути молочний продукт
}

//=============================================================================================================
BOOST_AUTO_TEST_CASE(Sousage_Product_Add)
{
    Deque* container = new Deque();
    BOOST_CHECK(!container->show_all()); // При створенні контейнер має бути пустим
    Sousages* sousage = new Sousages("tes2", "tes2", 22.22, 22.22, "test2");
    container->add_element(sousage);
    BOOST_CHECK(container->show_all()); // В контенері повинна бути ковбасний продукт
}

//=============================================================================================================
BOOST_AUTO_TEST_CASE(popTest)
{
    Deque* container = new Deque();
    BOOST_CHECK(!container->show_all()); // При створенні контейнер має бути пустим
    Sousages* sousage = new Sousages("tes3", "tes3", 33.33, 33.33, "test3");
    container->add_element(sousage);
    BOOST_CHECK(container->show_all()); // В контенері повинна бути елементи
    container->remove_first_element();
    BOOST_CHECK(!container->show_all()); // Контейнер повинен стати пустим
}

//=============================================================================================================
BOOST_AUTO_TEST_CASE(LoadTest)
{
    Deque* container = new Deque();
    BOOST_CHECK(!container->show_all()); // При створенні контейнер має бути пустим
    container->load_from_file();
    BOOST_CHECK(container->show_all()); // В контенері повинні бути елементи
}

//=============================================================================================================
BOOST_AUTO_TEST_CASE(popAllTest)
{
    Deque* container = new Deque();
    BOOST_CHECK(!container->show_all()); // При створенні контейнер має бути пустим
    container->load_from_file();
    BOOST_CHECK(container->show_all()); // В контенері повинні бути елементи
    container->remove_all_elements();
    BOOST_CHECK(!container->show_all()); // Контейнер повинен стати пустим
}
//=============================================================================================================
BOOST_AUTO_TEST_CASE(check_sorting)
{
    Deque deque;
    Milk* test_milk = new Milk("tes4.3", "tes4.3", 22.22, 22.22, "test4.3");
    Sousages* test_sausage1 = new Sousages("tes4.2", "tes4.2", 33.33, 33.33, "test4.2");
    Sousages* test_sausage2 = new Sousages("tes4.1", "tes4.1", 11.11, 11.11, "test4");

    Node* front_element;

    deque.add_element(test_milk);        //22.22%
    deque.add_element(test_sausage1);    //33.33%
    deque.add_element(test_sausage2);    //11.11%


    deque.sort();                   //Очікувано Front=test_sausage2 -> test_milk -> test_sausage1=Back

    front_element = deque.get_first_element();
    BOOST_REQUIRE(front_element, test_sausage2);

    deque.remove_first_element();   //Очікувано Front=test_milk -> test_sausage1=Back

    front_element = deque.get_first_element();
    BOOST_REQUIRE(front_element, test_milk);

    deque.remove_first_element();   //Очікувано Front= test_sausage1=Back

    front_element = deque.get_first_element();
    BOOST_REQUIRE(front_element, test_sausage1);

    deque.remove_all_elements();
}
//=============================================================================================================
BOOST_AUTO_TEST_CASE(check_doing_request)
{
    Deque deque;
    Milk* test_milk = new Milk("test5.1", "test5.1", 11.11, 11.11, "test5.1");
    Sousages* test_sausage1 = new Sousages("test5.2", "test5.2", 22.22, 22.22, "test5.2");
    Sousages* test_sausage2 = new Sousages("test5.3", "test5.3", 33.33, 33.33, "test5.3");

    Node* front_element;

    deque.add_element(test_milk);        //11.11%
    deque.add_element(test_sausage1);    //22.22%
    deque.add_element(test_sausage1);    //33.33%

    const int control_fat = 15;     //Контрольна жирність для запиту
    const int num_of_goods = 1;     //Очікувана кількість знайдених продуктів

    int ctr = deque.do_request(control_fat); //Кількість продуктів, жирність яких не перевищує 15%

    BOOST_TEST(ctr == num_of_goods);

    deque.remove_all_elements();
}


BOOST_AUTO_TEST_SUITE_END()
