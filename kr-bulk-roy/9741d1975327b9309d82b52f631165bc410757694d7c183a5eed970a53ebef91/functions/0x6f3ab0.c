
undefined4 FUN_006f3ab0(int param_1,int param_2)

{
  int iVar1;
  
  if (param_2 == 0) {
    return 0;
  }
  iVar1 = (**(code **)(**(int **)(param_2 + 4) + 0xc))
                    (*(int **)(param_2 + 4),param_1 + 4,param_2 + 8,0);
  if (-1 < iVar1) {
    _wcsncpy_s((wchar_t *)(param_2 + 0x11c),0x400,(wchar_t *)(param_1 + 0x28),0x3ff);
    _wcsncpy_s((wchar_t *)(param_2 + 0x91c),0x400,(wchar_t *)(param_1 + 0x230),0x3ff);
    FID_conflict__wprintf((char *)L"Instance: %s\n",(wchar_t *)(param_1 + 0x28));
    FID_conflict__wprintf((char *)L" - Product: %s\n",(wchar_t *)(param_1 + 0x230));
    return 0;
  }
  *(int *)(param_2 + 0x111c) = *(int *)(param_2 + 0x111c) + 1;
  return 1;
}

