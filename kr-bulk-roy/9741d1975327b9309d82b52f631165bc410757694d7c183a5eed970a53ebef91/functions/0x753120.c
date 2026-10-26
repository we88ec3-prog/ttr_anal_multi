
undefined4 FUN_00753120(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  char cVar1;
  undefined4 uVar2;
  int unaff_ESI;
  undefined4 *unaff_EDI;
  
  if ((*(int *)(unaff_ESI + 0x13d0) != 0) &&
     ((*(uint *)(*(int *)(unaff_ESI + 0x13d0) + 0x28) >> 7 & 1) != 0)) {
    cVar1 = FUN_00746420();
    if (cVar1 != '\0') {
      cVar1 = (**(code **)(**(int **)(unaff_ESI + 0x13d0) + 0xe0))();
      if ((cVar1 != '\0') && (*(int *)(unaff_ESI + 0x13c4) != 0)) {
        uVar2 = (**(code **)(**(int **)(unaff_ESI + 0x13d0) + 0xc4))
                          (param_1,param_2,param_3,param_4);
        return uVar2;
      }
    }
  }
  *unaff_EDI = 0;
  return 1;
}

