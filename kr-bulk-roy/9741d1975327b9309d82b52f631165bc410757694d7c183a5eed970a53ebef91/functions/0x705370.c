
undefined4 FUN_00705370(int param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  char *_Str;
  undefined4 local_18 [2];
  undefined4 local_10;
  
  iVar6 = *(int *)(param_1 + 8) - *(int *)(param_1 + 0xc) >> 4;
  local_18[0] = FUN_006fec70(param_1,"tostring",8);
  local_10 = 4;
  FUN_006fb850(param_1,param_1 + 0x48,local_18,*(undefined4 *)(param_1 + 8));
  *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 0x10;
  iVar5 = 1;
  if (0 < iVar6) {
    do {
      puVar1 = *(undefined4 **)(param_1 + 8);
      *puVar1 = puVar1[-4];
      puVar1[1] = puVar1[-3];
      puVar1[2] = puVar1[-2];
      *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 0x10;
      puVar2 = (undefined4 *)FUN_006f50f0();
      puVar1 = *(undefined4 **)(param_1 + 8);
      *puVar1 = *puVar2;
      puVar1[1] = puVar2[1];
      puVar1[2] = puVar2[2];
      *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 0x10;
      FUN_006fe550(param_1,*(int *)(param_1 + 8) + -0x20,1);
      iVar3 = *(int *)(param_1 + 8);
      if (*(int *)(iVar3 + -8) != 4) {
        iVar3 = FUN_006fb5d0();
        if (iVar3 == 0) goto LAB_007054a9;
        if (*(uint *)(*(int *)(param_1 + 0x10) + 0x40) <= *(uint *)(*(int *)(param_1 + 0x10) + 0x44)
           ) {
          FUN_006fb3a0();
        }
        iVar3 = *(int *)(param_1 + 8);
      }
      _Str = (char *)(*(int *)(iVar3 + -0x10) + 0x10);
      if (_Str == (char *)0x0) {
LAB_007054a9:
        uVar4 = FUN_006f5f30(param_1,"\'tostring\' must return a string to \'print\'");
        return uVar4;
      }
      if (1 < iVar5) {
        iVar3 = FUN_00894fab();
        _fputs("\t",(FILE *)(iVar3 + 0x20));
      }
      iVar3 = FUN_00894fab();
      _fputs(_Str,(FILE *)(iVar3 + 0x20));
      *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + -0x10;
      iVar5 = iVar5 + 1;
    } while (iVar5 <= iVar6);
  }
  iVar5 = FUN_00894fab();
  _fputs("\n",(FILE *)(iVar5 + 0x20));
  return 0;
}

