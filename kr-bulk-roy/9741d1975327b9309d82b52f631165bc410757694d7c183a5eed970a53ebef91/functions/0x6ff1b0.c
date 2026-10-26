
undefined4 FUN_006ff1b0(int param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  
  uVar1 = *(undefined4 *)(param_1 + 0x34);
  uVar2 = FUN_006fec70(uVar1);
  puVar3 = (undefined4 *)FUN_006f9d80(uVar1);
  if (puVar3[2] == 0) {
    *puVar3 = 1;
    puVar3[2] = 1;
  }
  return uVar2;
}

