
undefined4 * FUN_00840fc0(int param_1,undefined4 *param_2,int param_3)

{
  uint uVar1;
  undefined4 *puVar2;
  bool bVar3;
  
  puVar2 = *(undefined4 **)(*(int *)(param_1 + 4) + 4);
  bVar3 = true;
  if (*(char *)((int)puVar2 + 0x89) == '\0') {
    uVar1 = *(uint *)(*(int *)(param_3 + 0x4c) + 0x16c);
    do {
      if ((uVar1 == 0) && (*(int *)(puVar2[0x13] + 0x16c) == 0)) {
        bVar3 = *(uint *)(*(int *)(param_3 + 0x4c) + 0x164) < *(uint *)(puVar2[0x13] + 0x164);
      }
      else {
        bVar3 = uVar1 < *(uint *)(puVar2[0x13] + 0x16c);
      }
      if (bVar3 == false) {
        puVar2 = (undefined4 *)puVar2[2];
      }
      else {
        puVar2 = (undefined4 *)*puVar2;
      }
    } while (*(char *)((int)puVar2 + 0x89) == '\0');
  }
  puVar2 = (undefined4 *)FUN_008412d0(&param_3,bVar3,param_3);
  *param_2 = *puVar2;
  *(undefined1 *)(param_2 + 1) = 1;
  return param_2;
}

