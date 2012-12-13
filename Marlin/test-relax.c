// This file is used as a build test case to determine if the linker
// supports the -relax option.  It checks for the bug documented at:
//   http://sourceware.org/bugzilla/show_bug.cgi?id=12161
// To use this test case, run:
//   avr-gcc -Wl,-relax -ffunction-sections -mmcu=atmega128 test-relax.c -o /dev/null 2>&1
// the above will segfault when the defect is present and return no
// output when ld is working properly.

void func2(int a) { }

void func1(void)
{
  func2(10);
}

int main(void)
{
  func1();
}
