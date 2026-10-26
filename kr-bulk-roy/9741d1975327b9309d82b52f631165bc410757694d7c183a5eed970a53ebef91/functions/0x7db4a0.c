
void FUN_007db4a0(void)

{
  float fVar1;
  undefined4 in_EAX;
  int iVar2;
  uint uVar3;
  undefined4 *unaff_ESI;
  int local_c;
  int local_8;
  
  *unaff_ESI = in_EAX;
  iVar2 = FUN_007c6b70();
  if (iVar2 == 0) {
    fVar1 = 0.0;
  }
  else {
    iVar2 = FUN_007c6390(iVar2);
    fVar1 = (float)iVar2;
  }
  unaff_ESI[1] = fVar1;
  if ((float)unaff_ESI[1] == 0.0) {
    local_c = 0;
    local_8 = 0;
    FUN_007c5f40(*unaff_ESI,&local_c);
    uVar3 = local_8 - local_c >> 0x1f;
    unaff_ESI[1] = (float)(int)((local_8 - local_c ^ uVar3) - uVar3);
  }
  return;
}

