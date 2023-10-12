#include "tests/utest.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

enum num_type {NEG, POS, ZERO};

UTEST(info, simple_run)
{
    int ret = system("./info");
    ASSERT_TRUE(ret==0);
    (void)ret;

}

UTEST(pendulum, simple_run)
{
    int ret = system("./pendulum > tmp_sub");
    ASSERT_TRUE(ret==0);
    ret = system("diff -w tests/pendulum.correct tmp_sub");
    ASSERT_TRUE(ret==0);
    ret = system("rm tmp_sub");
    (void)ret;
    
}

UTEST(linear_algebra, simple_run)
{
    int ret = system("./linear_algebra > tmp_sub");
    ASSERT_TRUE(ret==0);
    ret = system("diff -w tests/linear_algebra.correct tmp_sub");
    ASSERT_TRUE(ret==0);
    ret = system("rm tmp_sub");
    (void)ret;
    
}

UTEST(sqrt, pos)
{
    time_t t;
    double num;
    int ret;

    srand((unsigned int)time(&t));

    num = ((double)rand()/(double)(RAND_MAX)) * 5 + 10;

    char command_py[100];
    char command_c[100];
    
    sprintf(command_py,"python tests/sqrt.pyc %f > tmp_sol",
            num);
    sprintf(command_c,"./sqrt %f area > tmp_sub",
            num);

    ret = system(command_py);
    ASSERT_TRUE(ret==0);
    ret = system(command_c);
    ASSERT_TRUE(ret==0);
    ret = system("diff -w tmp_sol tmp_sub");
    ASSERT_TRUE(ret==0);
    ret = system("rm tmp_sol tmp_sub");
    (void)ret;
}


UTEST(sqrt, neg)
{
    double num;
    int ret;

    num = ((double)rand()/(double)(RAND_MAX)) * 5 - 15;

    char command_py[100];
    char command_c[100];
    
    sprintf(command_py,"python tests/sqrt.pyc %f > tmp_sol",
            num);
    sprintf(command_c,"./sqrt %f area > tmp_sub",
            num);

    ret = system(command_py);
    ASSERT_TRUE(ret==0);
    ret = system(command_c);
    ASSERT_TRUE(ret==0);
    ret = system("diff -w tmp_sol tmp_sub");
    ASSERT_TRUE(ret==0);
    ret = system("rm tmp_sol tmp_sub");
    (void)ret;
}


UTEST(sqrt, zero)
{
    double num;
    int ret;

    num = 0.0;
    char command_py[100];
    char command_c[100];
    
    sprintf(command_py,"python tests/sqrt.pyc %f > tmp_sol",
            num);
    sprintf(command_c,"./sqrt %f area > tmp_sub",
            num);

    ret = system(command_py);
    ASSERT_TRUE(ret==0);
    ret = system(command_c);
    ASSERT_TRUE(ret==0);
    ret = system("diff -w tmp_sol tmp_sub");
    ASSERT_TRUE(ret==0);
    ret = system("rm tmp_sol tmp_sub");
    (void)ret;
}


UTEST_MAIN();
