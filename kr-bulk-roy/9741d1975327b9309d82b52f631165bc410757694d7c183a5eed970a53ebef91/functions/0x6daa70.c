
float10 FUN_006daa70(void)

{
  float fVar1;
  short in_AX;
  float10 fVar2;
  float fVar3;
  undefined4 local_8;
  
  local_8 = 1.0;
  fVar1 = (float)(int)in_AX / 10000.0;
  if (fVar1 <= 0.0) {
    local_8 = 0.0;
  }
  else if (fVar1 < 1.0) {
    local_8 = fVar1;
  }
  fVar2 = (float10)FUN_006dacb0(local_8,0x3fe66666);
  fVar1 = (float)fVar2;
  if (fVar1 <= 0.0) {
    fVar3 = 0.0;
  }
  else {
    fVar3 = 1.0;
    if (fVar1 < 1.0) {
      return (float10)(fVar1 * 10000.0);
    }
  }
  return (float10)(fVar3 * 10000.0);
}

