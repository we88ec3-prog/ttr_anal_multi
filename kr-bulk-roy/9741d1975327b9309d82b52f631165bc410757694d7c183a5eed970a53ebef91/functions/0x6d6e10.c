
void FUN_006d6e10(int param_1,short *param_2)

{
  uint in_EAX;
  short *psVar1;
  undefined4 uVar2;
  uint uVar3;
  short *psVar4;
  
  if (in_EAX < 2) {
    uVar3 = 0;
  }
  else {
    uVar3 = (in_EAX - 2) / 0xc;
  }
  for (; uVar3 != 0; uVar3 = uVar3 - 1) {
    psVar4 = param_2 + 6;
    psVar1 = (short *)FUN_006d6d80(param_1,*(undefined4 *)(param_2 + 1),param_2[5]);
    if ((*(int *)(psVar1 + 2) != *(int *)(param_2 + 3)) || (*psVar1 != *psVar4)) {
      uVar2 = FUN_00536170();
      FUN_00535f20(param_1 + 0x10,uVar2);
      psVar1[0xc] = 0;
      psVar1[0xd] = 0;
    }
    *psVar1 = *psVar4;
    *(undefined4 *)(psVar1 + 2) = *(undefined4 *)(param_2 + 3);
    param_2 = psVar4;
  }
  return;
}

