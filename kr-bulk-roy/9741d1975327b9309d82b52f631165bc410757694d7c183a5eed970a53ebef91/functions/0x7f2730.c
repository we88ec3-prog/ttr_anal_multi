
void FUN_007f2730(void)

{
  undefined4 *puVar1;
  uint uVar2;
  undefined4 *in_ECX;
  uint uVar3;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_009046fe;
  local_10 = ExceptionList;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *in_ECX = IS3D::CParticle::vftable;
  local_8 = 0;
  uVar3 = 0;
  if ((int)(in_ECX[0x26] - in_ECX[0x25]) >> 2 != 0) {
    do {
      if (*(int *)(in_ECX[0x25] + uVar3 * 4) != 0) {
        puVar1 = *(undefined4 **)(in_ECX[0x25] + uVar3 * 4);
        if (puVar1 != (undefined4 *)0x0) {
          (**(code **)*puVar1)(1,uVar2);
        }
        *(undefined4 *)(in_ECX[0x25] + uVar3 * 4) = 0;
      }
      uVar3 = uVar3 + 1;
    } while (uVar3 < (uint)((int)(in_ECX[0x26] - in_ECX[0x25]) >> 2));
  }
  if (in_ECX[0x25] != 0) {
    FUN_0089120c(in_ECX[0x25]);
  }
  in_ECX[0x25] = 0;
  in_ECX[0x26] = 0;
  in_ECX[0x27] = 0;
  ExceptionList = local_10;
  return;
}

