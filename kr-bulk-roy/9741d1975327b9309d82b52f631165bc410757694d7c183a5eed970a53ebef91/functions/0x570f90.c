
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00570f90(void)

{
  uint uVar1;
  uint uVar2;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0090acbb;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_8 = 0;
  uVar2 = 0;
  do {
    if (*(undefined4 **)((int)&DAT_00fb1320 + uVar2) != (undefined4 *)0x0) {
      (**(code **)**(undefined4 **)((int)&DAT_00fb1320 + uVar2))(1,uVar1);
      *(undefined4 *)((int)&DAT_00fb1320 + uVar2) = 0;
    }
    uVar2 = uVar2 + 4;
  } while (uVar2 < 0xc);
  if (7 < DAT_00fb1348) {
    FUN_0089120c(DAT_00fb1334);
  }
  DAT_00fb1348 = 7;
  _DAT_00fb1344 = 0;
  DAT_00fb1334 = DAT_00fb1334 & 0xffff0000;
  ExceptionList = local_10;
  return;
}

