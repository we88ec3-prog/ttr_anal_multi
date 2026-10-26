
void FUN_008943fb(char *param_1,rsize_t param_2,char *param_3)

{
  errno_t eVar1;
  
  eVar1 = _strcpy_s(param_1,param_2,param_3);
  if (eVar1 == 0) {
    if (param_3[0x40] != '\0') {
      FUN_0089429b(param_1,param_2,2,&DAT_00c43a90,param_3 + 0x40);
    }
    if (param_3[0x80] != '\0') {
      FUN_0089429b(param_1,param_2,2,&DAT_00c41190,param_3 + 0x80);
    }
    return;
  }
                    /* WARNING: Subroutine does not return */
  __invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);
}

