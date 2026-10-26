
undefined4
FUN_00550580(char *param_1,char *param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5)

{
  char *pcVar1;
  char cVar2;
  undefined4 uVar3;
  uint uVar4;
  int *piVar5;
  undefined4 in_ECX;
  undefined4 *in_EDX;
  undefined4 *unaff_EDI;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0091df6e;
  local_10 = ExceptionList;
  uVar4 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  in_EDX[0x1b] = param_3;
  in_EDX[0x1c] = in_ECX;
  in_EDX[0x1d] = 0;
  *in_EDX = *unaff_EDI;
  in_EDX[1] = unaff_EDI[1];
  uVar3 = unaff_EDI[2];
  in_EDX[3] = 0;
  in_EDX[6] = param_5;
  in_EDX[4] = 0;
  in_EDX[2] = uVar3;
  in_EDX[7] = param_5;
  in_EDX[5] = param_4;
  in_EDX[8] = param_5;
  _strcpy_s((char *)(in_EDX + 0xb),0x40,param_1);
  FUN_005506b0(uVar4);
  if (param_2 != (char *)0x0) {
    pcVar1 = param_2 + 1;
    do {
      cVar2 = *param_2;
      param_2 = param_2 + 1;
    } while (cVar2 != '\0');
    if (param_2 != pcVar1) {
      if ((DAT_00fab0d4 & 1) == 0) {
        DAT_00fab0d4 = DAT_00fab0d4 | 1;
        local_8 = 0;
        FUN_0080a3a0();
        _atexit((_func_4879 *)&LAB_00bccdd0);
        local_8 = 0xffffffff;
      }
      piVar5 = (int *)FUN_0080af10();
      if (piVar5 != (int *)0x0) {
        in_EDX[10] = piVar5;
        (**(code **)(*piVar5 + 0xc))();
      }
    }
  }
  ExceptionList = local_10;
  return 1;
}

