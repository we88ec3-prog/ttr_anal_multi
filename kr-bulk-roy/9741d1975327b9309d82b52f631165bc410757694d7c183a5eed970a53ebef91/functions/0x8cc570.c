
undefined4 FUN_008cc570(int *param_1,int *param_2)

{
  short *psVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  
  psVar1 = (short *)param_2[1];
  piVar2 = (int *)*param_2;
  if (((param_1 == (int *)0x0) || (*param_1 == 0)) || (param_1[1] == 0)) {
    return 0x60;
  }
  if (psVar1 == (short *)0x0) {
    return 0x14;
  }
  if ((psVar1[1] != 0) && (0 < *psVar1)) {
    if ((*(int *)(psVar1 + 6) != 0) &&
       ((*(int *)(psVar1 + 2) != 0 &&
        ((int)psVar1[1] == *(short *)(*(int *)(psVar1 + 6) + -2 + *psVar1 * 2) + 1)))) {
      iVar3 = param_1[3];
      if ((*(byte *)(param_2 + 2) & 2) != 0) {
        return 0x13;
      }
      if (piVar2 != (int *)0x0) {
        if (piVar2[1] == 0) {
          return 0;
        }
        if (*piVar2 == 0) {
          return 0;
        }
        if (piVar2[3] != 0) {
          *(undefined4 *)(iVar3 + 0x80) = *(undefined4 *)psVar1;
          *(undefined4 *)(iVar3 + 0x84) = *(undefined4 *)(psVar1 + 2);
          *(undefined4 *)(iVar3 + 0x88) = *(undefined4 *)(psVar1 + 4);
          *(undefined4 *)(iVar3 + 0x8c) = *(undefined4 *)(psVar1 + 6);
          *(undefined4 *)(iVar3 + 0x90) = *(undefined4 *)(psVar1 + 8);
          *(int *)(iVar3 + 0x68) = *piVar2;
          *(int *)(iVar3 + 0x6c) = piVar2[1];
          *(int *)(iVar3 + 0x70) = piVar2[2];
          *(int *)(iVar3 + 0x74) = piVar2[3];
          *(int *)(iVar3 + 0x78) = piVar2[4];
          *(int *)(iVar3 + 0x7c) = piVar2[5];
          iVar4 = *param_1;
          *(int *)(iVar3 + 0x1c) = iVar4;
          *(uint *)(iVar3 + 0x20) = iVar4 + (param_1[1] & 0xfffffffcU);
          if ((*(byte *)(param_2 + 2) & 1) == 0) {
            uVar5 = FUN_008cc390();
            return uVar5;
          }
          uVar5 = FUN_007f15a0();
          return uVar5;
        }
      }
    }
    return 0x14;
  }
  return 0;
}

