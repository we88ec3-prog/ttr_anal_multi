
void FUN_0041b470(void)

{
  uint *puVar1;
  undefined4 *puVar2;
  void *_Dst;
  undefined4 *puVar3;
  undefined4 *puVar4;
  uint uVar5;
  int in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00927cfe;
  local_10 = ExceptionList;
  uVar5 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  _Dst = *(void **)(in_ECX + 0x118);
  puVar1 = (uint *)(in_ECX + 0x118);
  if (_Dst != *(void **)(in_ECX + 0x11c)) {
    FID_conflict__memcpy(_Dst,*(void **)(in_ECX + 0x11c),0);
    *(void **)(in_ECX + 0x11c) = _Dst;
  }
  if ((DAT_00fb725c & 1) == 0) {
    DAT_00fb725c = DAT_00fb725c | 1;
    local_8 = 0;
    FUN_004a79a0(uVar5);
    _atexit((_func_4879 *)&DAT_00bccf80);
    local_8 = 0xffffffff;
  }
  uVar5 = 0;
  if (DAT_00fb7294 - DAT_00fb7290 >> 2 != 0) {
    do {
      puVar2 = (undefined4 *)(DAT_00fb7290 + uVar5 * 4);
      if (*(char *)(*(int *)(DAT_00fb7290 + uVar5 * 4) + 9) == '\0') {
        puVar3 = *(undefined4 **)(in_ECX + 0x11c);
        if ((puVar2 < puVar3) && (puVar4 = (undefined4 *)*puVar1, puVar4 <= puVar2)) {
          if (puVar3 == *(undefined4 **)(in_ECX + 0x120)) {
            FUN_004deab0();
          }
          if (*(undefined4 **)(in_ECX + 0x11c) != (undefined4 *)0x0) {
            **(undefined4 **)(in_ECX + 0x11c) =
                 *(undefined4 *)(*puVar1 + ((int)puVar2 - (int)puVar4 >> 2) * 4);
          }
        }
        else {
          if (puVar3 == *(undefined4 **)(in_ECX + 0x120)) {
            FUN_004deab0();
          }
          if (*(undefined4 **)(in_ECX + 0x11c) != (undefined4 *)0x0) {
            **(undefined4 **)(in_ECX + 0x11c) = *puVar2;
          }
        }
        *(int *)(in_ECX + 0x11c) = *(int *)(in_ECX + 0x11c) + 4;
      }
      else {
        FUN_0044a480(puVar1,*puVar1);
      }
      uVar5 = uVar5 + 1;
    } while (uVar5 < (uint)(DAT_00fb7294 - DAT_00fb7290 >> 2));
  }
  ExceptionList = local_10;
  return;
}

