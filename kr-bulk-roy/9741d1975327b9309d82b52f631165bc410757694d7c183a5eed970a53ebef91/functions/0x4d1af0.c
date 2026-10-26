
undefined4 FUN_004d1af0(float param_1)

{
  float fVar1;
  undefined4 uVar2;
  int *in_ECX;
  float fVar3;
  
  fVar1 = param_1 + (float)in_ECX[0x10b];
  in_ECX[0x10b] = (int)fVar1;
  if (param_1 <= 0.028571429) {
    if (param_1 <= 0.02) goto LAB_004d1b5a;
    fVar3 = 0.033333335;
  }
  else {
    fVar3 = 0.06666667;
  }
  if (fVar1 < fVar3) {
    FUN_007a5bb0();
    return 0;
  }
LAB_004d1b5a:
  in_ECX[0x10b] = 0;
  uVar2 = FUN_004c87d0(fVar1);
  (**(code **)(*in_ECX + 100))();
  return uVar2;
}

