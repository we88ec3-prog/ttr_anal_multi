
uint FUN_006fee90(void *param_1,uint param_2)

{
  byte bVar1;
  byte *pbVar2;
  uint uVar3;
  uint *unaff_ESI;
  uint _Size;
  
  uVar3 = param_2;
  do {
    if (uVar3 == 0) {
      return 0;
    }
    if (*unaff_ESI == 0) {
      pbVar2 = (byte *)(*(code *)unaff_ESI[2])(unaff_ESI[4],unaff_ESI[3],&param_2);
      if (pbVar2 == (byte *)0x0) {
        return uVar3;
      }
      if (param_2 == 0) {
        return uVar3;
      }
      unaff_ESI[1] = (uint)pbVar2;
      *unaff_ESI = param_2 - 1;
      bVar1 = *pbVar2;
      unaff_ESI[1] = (uint)(pbVar2 + 1);
      if (bVar1 == 0xffffffff) {
        return uVar3;
      }
      *unaff_ESI = param_2;
      unaff_ESI[1] = (uint)pbVar2;
    }
    if (*(byte *)unaff_ESI[1] == 0xffffffff) {
      return uVar3;
    }
    _Size = *unaff_ESI;
    if (uVar3 <= *unaff_ESI) {
      _Size = uVar3;
    }
    FID_conflict__memcpy(param_1,(byte *)unaff_ESI[1],_Size);
    *unaff_ESI = *unaff_ESI - _Size;
    unaff_ESI[1] = unaff_ESI[1] + _Size;
    param_1 = (void *)((int)param_1 + _Size);
    uVar3 = uVar3 - _Size;
  } while( true );
}

