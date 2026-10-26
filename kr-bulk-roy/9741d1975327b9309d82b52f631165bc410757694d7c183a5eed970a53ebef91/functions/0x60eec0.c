
void FUN_0060eec0(void)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  int *in_ECX;
  int iVar4;
  int local_1c;
  
  iVar4 = 0;
  local_1c = 0;
  if ((*(int *)(in_ECX[0x5f] + 0xf8) != 0) || (*(int *)(in_ECX[0x60] + 0xf8) != 0)) {
    local_1c = 0x14;
    iVar4 = 0x14;
  }
  if (*(int *)(in_ECX[0x61] + 0xf8) != 0) {
    FUN_00749a00(*(undefined4 *)(in_ECX[0x61] + 8),*(int *)(in_ECX[0x5f] + 0xc) + iVar4);
    FUN_007545b0();
    iVar4 = iVar4 + (*(int *)(in_ECX[0x61] + 0x14) - *(int *)(in_ECX[0x61] + 0xc));
    local_1c = iVar4;
  }
  if (*(int *)(in_ECX[0x5d] + 0xf8) == 0) {
    if (*(int *)(in_ECX[0x5e] + 0xf8) == 0) goto LAB_0060efe6;
  }
  else {
    FUN_00749a00(*(undefined4 *)(in_ECX[0x5d] + 8),*(int *)(in_ECX[0x5f] + 0xc) + iVar4);
    FUN_007545b0();
  }
  if (*(int *)(in_ECX[0x5e] + 0xf8) != 0) {
    FUN_00749a00(*(undefined4 *)(in_ECX[0x5e] + 8),*(int *)(in_ECX[0x5f] + 0xc) + iVar4);
    FUN_007545b0();
  }
  iVar1 = in_ECX[0x5d];
  iVar2 = in_ECX[0x5e];
  if (*(int *)(iVar2 + 0x14) - *(int *)(iVar2 + 0xc) <
      *(int *)(iVar1 + 0x14) - *(int *)(iVar1 + 0xc)) {
    local_1c = *(int *)(iVar1 + 0x14) - *(int *)(iVar1 + 0xc);
  }
  else {
    local_1c = *(int *)(iVar2 + 0x14) - *(int *)(iVar2 + 0xc);
  }
  local_1c = iVar4 + local_1c;
LAB_0060efe6:
  iVar4 = in_ECX[100];
  if (*(int *)(iVar4 + 0xcc) == 0) {
    piVar3 = (int *)0x0;
  }
  else {
    piVar3 = (int *)(*(int *)(iVar4 + 0xcc) + 0xa8);
  }
  if ((piVar3[1] - *piVar3 & 0xfffffffcU) == 0) {
    iVar4 = 0;
  }
  else {
    iVar4 = *(int *)(iVar4 + 0x14) - *(int *)(iVar4 + 0xc);
  }
  FUN_00749a00(*(undefined4 *)(in_ECX[0x62] + 8),local_1c + 0x3c);
  FUN_007545b0();
  FUN_00749a00(*(undefined4 *)(in_ECX[100] + 8),*(int *)(in_ECX[0x62] + 0x14) + 5);
  iVar1 = in_ECX[0x59];
  iVar4 = *(int *)(in_ECX[0x62] + 0x14) + 0x11 + iVar4;
  (**(code **)(*(int *)in_ECX[0x59] + 0xbc))
            (*(undefined4 *)(iVar1 + 8),*(int *)(iVar1 + 0xc),*(undefined4 *)(iVar1 + 0x10),
             *(int *)(iVar1 + 0xc) + iVar4);
  (**(code **)(*in_ECX + 0xbc))(in_ECX[2],in_ECX[3],in_ECX[4],in_ECX[3] + iVar4);
  return;
}

