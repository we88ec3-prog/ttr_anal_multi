
void FUN_0085ff00(void)

{
  undefined4 *puVar1;
  uint uVar2;
  undefined4 *in_ECX;
  undefined1 local_18 [8];
  void *local_10;
  undefined1 *puStack_c;
  uint local_8;
  
  puStack_c = &LAB_0091119f;
  local_10 = ExceptionList;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *in_ECX = gbSkeletal::vftable;
  puVar1 = in_ECX + 0x1e;
  local_8 = 3;
  FUN_00860810(puVar1,local_18,*puVar1,in_ECX[0x1f]);
  if ((undefined4 *)in_ECX[0x1d] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[0x1d])(1,uVar2);
    in_ECX[0x1d] = 0;
  }
  if (in_ECX[0x26] != 0) {
    FUN_0089120c(in_ECX[0x26]);
  }
  in_ECX[0x26] = 0;
  in_ECX[0x27] = 0;
  in_ECX[0x28] = 0;
  if (in_ECX[0x22] != 0) {
    FUN_0089120c(in_ECX[0x22]);
  }
  in_ECX[0x22] = 0;
  in_ECX[0x23] = 0;
  in_ECX[0x24] = 0;
  local_8 = local_8 & 0xffffff00;
  FUN_00860880(puVar1);
  local_8 = 0xffffffff;
  *in_ECX = gbObject3d::vftable;
  FUN_00780000();
  ExceptionList = local_10;
  return;
}

