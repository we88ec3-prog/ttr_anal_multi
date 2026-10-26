
void FUN_004d0a10(void)

{
  int iVar1;
  undefined4 uVar2;
  int unaff_EDI;
  int local_18;
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0091b411;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if ((DAT_00f8d9a4 & 1) == 0) {
    DAT_00f8d9a4 = DAT_00f8d9a4 | 1;
    local_8 = 0;
    FUN_0051c120(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
    _atexit((_func_4879 *)&LAB_00bccc90);
  }
  local_8 = 0xffffffff;
  local_14 = *(int *)(unaff_EDI + 0x11c);
  FUN_008438c0(&local_14);
  if ((local_18 != DAT_00f8d91c) && (iVar1 = *(int *)(local_18 + 0x10), iVar1 != 0)) {
    FUN_004026e0(iVar1,0,0xffffffff);
    if ((DAT_00f8d9a8 & 1) == 0) {
      DAT_00f8d9a8 = DAT_00f8d9a8 | 1;
      local_8 = 1;
      FUN_00523540();
      local_8 = CONCAT31(local_8._1_3_,2);
      FUN_00521080(&DAT_00f8d9bc);
      _atexit((_func_4879 *)&LAB_00bccc50);
    }
    local_18 = *(int *)(iVar1 + 0x20);
    FUN_008438c0(&local_18);
    if ((local_14 != DAT_00f8d9b0) && (iVar1 = *(int *)(local_14 + 0x10), iVar1 != 0)) {
      if (*(int *)(iVar1 + 8) == 0xf) {
        uVar2 = 0xffcccccc;
      }
      else {
        switch(*(undefined4 *)(iVar1 + 0x68)) {
        case 0:
          uVar2 = 0xffffffff;
          break;
        case 1:
          uVar2 = 0xffffff00;
          break;
        case 2:
          uVar2 = 0xff5aff78;
          break;
        case 3:
          uVar2 = 0xff00bbdd;
          break;
        case 4:
          uVar2 = 0xffe243ff;
          break;
        case 5:
          uVar2 = 0xffb41010;
          break;
        default:
          uVar2 = 0xff6600;
        }
      }
      *(undefined4 *)(unaff_EDI + 0x120) = uVar2;
    }
  }
  ExceptionList = local_10;
  return;
}

