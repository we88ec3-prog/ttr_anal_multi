
void FUN_004e61b0(void)

{
  uint uVar1;
  int *piVar2;
  int in_ECX;
  uint uVar3;
  tagRECT local_2c;
  tagRECT tStack_1c;
  uint local_c;
  
  local_c = DAT_00d61f20 ^ (uint)&local_2c;
  if (((*(int *)(in_ECX + 0x34) != 0) && (*(int *)(in_ECX + 0x34) != 1)) &&
     (*(int *)(in_ECX + 0x44) != 0)) {
    local_2c.right = 0x40;
    local_2c.bottom = 0x40;
    uVar1 = (*(int *)(in_ECX + 0x68) + -1) / 6;
    uVar3 = uVar1 & 0x80000003;
    local_2c.left = 0;
    local_2c.top = 0;
    if ((int)uVar3 < 0) {
      uVar3 = (uVar3 - 1 | 0xfffffffc) + 1;
    }
    OffsetRect(&local_2c,uVar3 << 6,((int)(uVar1 + ((int)uVar1 >> 0x1f & 3U)) >> 2) << 6);
    (**(code **)(**(int **)(in_ECX + 0x44) + 0x24))
              (*(undefined4 *)(in_ECX + 0xc),*(undefined4 *)(in_ECX + 0x10),&local_2c,0,1,0,
               (uint)*(byte *)(in_ECX + 0x38) << 0x18 | 0xffffff);
    piVar2 = (int *)FUN_004cd030();
    piVar2 = (int *)*piVar2;
    if (piVar2 != (int *)0x0) {
      tStack_1c.left = 0;
      tStack_1c.top = 0;
      tStack_1c.right = 0x20;
      tStack_1c.bottom = 0x20;
      OffsetRect(&tStack_1c,(5 - (*(int *)(in_ECX + 0x68) + -1) % 6) * 0x20,0x20);
      (**(code **)(*piVar2 + 0x20))
                (*(undefined4 *)(in_ECX + 0xc),*(undefined4 *)(in_ECX + 0x10),&tStack_1c,
                 (uint)*(byte *)(in_ECX + 0x38) << 0x18 | 0xffffff);
    }
  }
  __security_check_cookie(local_c ^ (uint)&local_2c);
  return;
}

