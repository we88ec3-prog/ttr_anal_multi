
/* Library Function - Single Match
    ___initmbctable
   
   Libraries: Visual Studio 2008 Release, Visual Studio 2010 Release */

undefined4 ___initmbctable(void)

{
  if (DAT_00fe83d0 == 0) {
    __setmbcp(-3);
    DAT_00fe83d0 = 1;
  }
  return 0;
}

