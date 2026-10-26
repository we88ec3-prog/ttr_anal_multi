
undefined4 FUN_007684e0(undefined4 param_1)

{
  char cVar1;
  undefined1 uVar2;
  int in_ECX;
  float10 fVar3;
  
  cVar1 = FUN_007692c0(param_1);
  if (cVar1 != '\0') {
    FUN_00756010(in_ECX + 300);
    FUN_00429860(in_ECX + 0x128);
    FUN_00429860(in_ECX + 0x130);
    fVar3 = (float10)FUN_00764f00(*(undefined4 *)(in_ECX + 0x124));
    *(float *)(in_ECX + 0x124) = (float)fVar3;
    uVar2 = FUN_00765120(*(undefined1 *)(in_ECX + 0x148));
    *(undefined1 *)(in_ECX + 0x148) = uVar2;
    return 1;
  }
  return 0;
}

