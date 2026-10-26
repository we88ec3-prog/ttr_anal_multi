
bool FUN_006f7760(void)

{
  double dVar1;
  ulong uVar2;
  int iVar3;
  byte *unaff_ESI;
  double *unaff_EDI;
  float10 fVar4;
  byte *local_8;
  
  fVar4 = (float10)FUN_00898a3f();
  *unaff_EDI = (double)fVar4;
  if (local_8 == unaff_ESI) {
    return false;
  }
  if ((*local_8 == 0x78) || (*local_8 == 0x58)) {
    uVar2 = _strtoul((char *)unaff_ESI,(char **)&local_8,0x10);
    dVar1 = (double)(int)uVar2;
    if ((int)uVar2 < 0) {
      dVar1 = dVar1 + 4294967296.0;
    }
    *unaff_EDI = dVar1;
  }
  if (*local_8 != 0) {
    iVar3 = _isspace((uint)*local_8);
    while (iVar3 != 0) {
      local_8 = local_8 + 1;
      iVar3 = _isspace((uint)*local_8);
    }
    return *local_8 == 0;
  }
  return true;
}

