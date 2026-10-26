
void FUN_006389e0(int param_1,uint param_2)

{
  int iVar1;
  int *piVar2;
  undefined4 uVar3;
  uint uVar4;
  int local_8;
  
  FUN_00823850();
  iVar1 = DAT_00fe1bd0;
  FUN_008438c0(&param_2);
  if ((local_8 != *(int *)(iVar1 + 0xc)) && (*(int *)(local_8 + 0x10) != 0)) {
    *(undefined1 *)(param_1 + 0x17c) = *(undefined1 *)(*(int *)(local_8 + 0x10) + 0x20);
    piVar2 = (int *)FUN_0063a820(param_1 + 200);
    uVar4 = piVar2[1] - *piVar2 >> 2;
    param_2 = 0;
    if (uVar4 != 0) {
      do {
        if (*(int *)(param_1 + 0xb8) != 0) {
          FUN_0053f8a0();
        }
        uVar3 = FUN_0057ef20();
        FUN_0082f200(param_1 + 0xb0,uVar3);
        param_2 = param_2 + 1;
      } while (param_2 < uVar4);
    }
  }
  return;
}

