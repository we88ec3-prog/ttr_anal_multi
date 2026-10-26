
/* WARNING: Removing unreachable block (ram,0x006931d2) */

void FUN_00693130(void)

{
  uint uVar1;
  int in_ECX;
  undefined4 *puVar2;
  int iVar3;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00912470;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  puVar2 = (undefined4 *)(in_ECX + 0x80);
  iVar3 = 4;
  do {
    (**(code **)(*(int *)*puVar2 + 0x74))(puVar2[4],uVar1);
    puVar2 = puVar2 + 1;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  if (DAT_00f7fc70 != 0) {
    DAT_00f7fc70 = 0;
  }
  local_8 = 1;
  FUN_004095e0(0x1b);
  FUN_004095e0(0x1c);
  FUN_004095e0(0x1d);
  FUN_004095e0(0x1e);
  ExceptionList = local_10;
  return;
}

