
undefined4 FUN_005cb3c0(HWND param_1,undefined4 param_2,DWORD param_3)

{
  int *piVar1;
  HWND pHVar2;
  char cVar3;
  HIMC pHVar4;
  int in_ECX;
  
  piVar1 = *(int **)(*(int *)(in_ECX + 4) + 0x14);
  if ((param_3 == 6) && (piVar1 != (int *)0x0)) {
    cVar3 = (**(code **)(*piVar1 + 0x188))();
    pHVar2 = param_1;
    if (cVar3 != '\0') {
      pHVar4 = ImmGetContext(param_1);
      ImmGetConversionStatus(pHVar4,&param_3,(LPDWORD)&param_1);
      if ((param_3 != 0) || (param_1 != (HWND)0x4)) {
        ImmSetConversionStatus(pHVar4,0,4);
      }
      ImmReleaseContext(pHVar2,pHVar4);
      return 0;
    }
  }
  return 1;
}

