
void FUN_00711c00(int param_1)

{
  uint *puVar1;
  int iVar2;
  uint uVar3;
  int *in_EAX;
  uint in_ECX;
  
  iVar2 = in_EAX[6];
  if (in_EAX[7] < iVar2) {
    if (iVar2 == 0) {
      if ((int)(uint)*(byte *)((int)in_EAX + 0x32) <= (int)in_ECX) {
        return;
      }
    }
    else {
      puVar1 = (uint *)(*(int *)(*in_EAX + 0xc) + -4 + iVar2 * 4);
      uVar3 = *puVar1;
      if (((((byte)uVar3 & 0x3f) == 3) && ((int)(uVar3 >> 6 & 0xff) <= (int)in_ECX)) &&
         ((int)in_ECX <= (int)((uVar3 >> 0x17) + 1))) {
        if ((int)((in_ECX - 1) + param_1) <= (int)(uVar3 >> 0x17)) {
          return;
        }
        *puVar1 = ((in_ECX - 1) + param_1) * 0x800000 | uVar3 & 0x7fffff;
        return;
      }
    }
  }
  FUN_00713370((((in_ECX - 1) + param_1) * 0x20000 | in_ECX) << 6 | 3,*(undefined4 *)(in_EAX[3] + 8)
              );
  return;
}

