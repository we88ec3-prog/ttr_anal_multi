
int FUN_008e20c0(int param_1,undefined4 *param_2)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  int iVar5;
  
  iVar5 = param_1;
  iVar1 = *(int *)(param_1 + 0x290);
  iVar2 = 0;
  param_1 = 0;
  if (iVar1 != 0) {
    if (*(int *)(iVar1 + 0xb90) == 0) {
      puVar3 = (undefined4 *)FUN_008baee0(*(undefined4 *)(iVar5 + 100),0x20,&param_1);
      if (param_1 != 0) {
        return param_1;
      }
      uVar4 = FUN_008de030();
      *puVar3 = uVar4;
      uVar4 = FUN_008de030();
      puVar3[1] = uVar4;
      uVar4 = FUN_008de030();
      puVar3[2] = uVar4;
      uVar4 = FUN_008de030();
      puVar3[3] = uVar4;
      uVar4 = FUN_008de030();
      puVar3[4] = uVar4;
      puVar3[5] = *(undefined4 *)(iVar1 + 0x548);
      *(undefined1 *)(puVar3 + 6) = *(undefined1 *)(iVar1 + 0x544);
      *(undefined2 *)((int)puVar3 + 0x1a) = *(undefined2 *)(iVar1 + 0x54c);
      *(undefined2 *)(puVar3 + 7) = *(undefined2 *)(iVar1 + 0x550);
      *(undefined4 **)(iVar1 + 0xb90) = puVar3;
      iVar2 = param_1;
    }
    puVar3 = *(undefined4 **)(iVar1 + 0xb90);
    for (iVar5 = 8; iVar5 != 0; iVar5 = iVar5 + -1) {
      *param_2 = *puVar3;
      puVar3 = puVar3 + 1;
      param_2 = param_2 + 1;
    }
  }
  return iVar2;
}

