
void FUN_007d4e00(void)

{
  undefined4 *puVar1;
  uint uVar2;
  undefined4 *in_ECX;
  uint uVar3;
  uint uVar4;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00909e7b;
  local_10 = ExceptionList;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *in_ECX = IS3D::CItemBase::vftable;
  local_8 = 2;
  uVar4 = 0;
  uVar3 = (int)(in_ECX[0xb] - in_ECX[10]) >> 2;
  if (uVar3 != 0) {
    do {
      if (*(int *)(in_ECX[10] + uVar4 * 4) != 0) {
        puVar1 = *(undefined4 **)(in_ECX[10] + uVar4 * 4);
        if (puVar1 != (undefined4 *)0x0) {
          (**(code **)*puVar1)(1,uVar2);
        }
        *(undefined4 *)(in_ECX[10] + uVar4 * 4) = 0;
      }
      uVar4 = uVar4 + 1;
    } while (uVar4 < uVar3);
  }
  local_8 = CONCAT31(local_8._1_3_,3);
  FUN_005540c0(*(undefined4 *)in_ECX[0x10],(undefined4 *)in_ECX[0x10]);
  FUN_0089120c(in_ECX[0x10]);
  if (in_ECX[10] != 0) {
    FUN_0089120c(in_ECX[10]);
  }
  in_ECX[10] = 0;
  in_ECX[0xb] = 0;
  in_ECX[0xc] = 0;
  if (0xf < (uint)in_ECX[6]) {
    FUN_0089120c(in_ECX[1]);
  }
  in_ECX[6] = 0xf;
  in_ECX[5] = 0;
  *(undefined1 *)(in_ECX + 1) = 0;
  ExceptionList = local_10;
  return;
}

