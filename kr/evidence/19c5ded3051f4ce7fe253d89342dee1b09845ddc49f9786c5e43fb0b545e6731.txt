
undefined4 FUN_0044ab70(undefined4 *param_1)

{
  void *_Dst;
  undefined4 *puVar1;
  undefined4 *puVar2;
  uint in_EAX;
  uint uVar3;
  uint *unaff_ESI;
  
  uVar3 = in_EAX >> 2;
  _Dst = (void *)*unaff_ESI;
  if (_Dst != (void *)unaff_ESI[1]) {
    FID_conflict__memcpy(_Dst,(void *)unaff_ESI[1],0);
    unaff_ESI[1] = (uint)_Dst;
  }
  for (; uVar3 != 0; uVar3 = uVar3 - 1) {
    puVar1 = (undefined4 *)unaff_ESI[1];
    if ((param_1 < puVar1) && (puVar2 = (undefined4 *)*unaff_ESI, puVar2 <= param_1)) {
      if (puVar1 == (undefined4 *)unaff_ESI[2]) {
        FUN_006d6240();
      }
      if ((undefined4 *)unaff_ESI[1] != (undefined4 *)0x0) {
        *(undefined4 *)unaff_ESI[1] =
             *(undefined4 *)(*unaff_ESI + ((int)param_1 - (int)puVar2 >> 2) * 4);
      }
    }
    else {
      if (puVar1 == (undefined4 *)unaff_ESI[2]) {
        FUN_006d6240();
      }
      if ((undefined4 *)unaff_ESI[1] != (undefined4 *)0x0) {
        *(undefined4 *)unaff_ESI[1] = *param_1;
      }
    }
    unaff_ESI[1] = unaff_ESI[1] + 4;
    param_1 = param_1 + 1;
  }
  return 1;
}

