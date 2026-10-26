
void FUN_007ffef0(void)

{
  undefined4 *puVar1;
  void *_Dst;
  uint uVar2;
  undefined4 *in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00905306;
  local_10 = ExceptionList;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *in_ECX = IS3D::CParticleBase::vftable;
  local_8 = 1;
  if ((undefined4 *)in_ECX[3] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[3])(1,uVar2);
    in_ECX[3] = 0;
  }
  uVar2 = 0;
  if ((int)(in_ECX[0x17] - in_ECX[0x16]) >> 2 != 0) {
    do {
      if (*(int *)(in_ECX[0x16] + uVar2 * 4) != 0) {
        puVar1 = *(undefined4 **)(in_ECX[0x16] + uVar2 * 4);
        if (puVar1 != (undefined4 *)0x0) {
          (**(code **)*puVar1)(1);
        }
        *(undefined4 *)(in_ECX[0x16] + uVar2 * 4) = 0;
      }
      uVar2 = uVar2 + 1;
    } while (uVar2 < (uint)((int)(in_ECX[0x17] - in_ECX[0x16]) >> 2));
  }
  _Dst = (void *)in_ECX[0x16];
  if (_Dst != (void *)in_ECX[0x17]) {
    FID_conflict__memcpy(_Dst,(void *)in_ECX[0x17],0);
    in_ECX[0x17] = _Dst;
  }
  if (in_ECX[0x16] != 0) {
    FUN_0089120c(in_ECX[0x16]);
  }
  in_ECX[0x16] = 0;
  in_ECX[0x17] = 0;
  in_ECX[0x18] = 0;
  if (0xf < (uint)in_ECX[10]) {
    FUN_0089120c(in_ECX[5]);
  }
  in_ECX[10] = 0xf;
  in_ECX[9] = 0;
  *(undefined1 *)(in_ECX + 5) = 0;
  ExceptionList = local_10;
  return;
}

