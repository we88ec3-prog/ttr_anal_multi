
/* Library Function - Single Match
    __un_inc
   
   Library: Visual Studio 2010 Release */

void __un_inc(wint_t param_1,FILE *param_2)

{
  if (param_1 != 0xffff) {
    __ungetwc_nolock(param_1,param_2);
    return;
  }
  return;
}

