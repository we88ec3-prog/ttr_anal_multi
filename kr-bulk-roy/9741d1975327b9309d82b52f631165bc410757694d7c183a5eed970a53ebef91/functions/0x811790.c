
void FUN_00811790(void)

{
  int iVar1;
  uint uVar2;
  int unaff_ESI;
  undefined1 *puVar3;
  int local_40c;
  undefined1 local_408 [1024];
  uint local_8;
  
  local_8 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  (**(code **)(unaff_ESI + 0x30))();
  uVar2 = 0;
  puVar3 = local_408;
  do {
    (**(code **)(unaff_ESI + 0x60))(1,puVar3);
    iVar1 = (**(code **)(unaff_ESI + 0x30))();
    if (iVar1 != 0) break;
    uVar2 = uVar2 + 1;
    puVar3 = puVar3 + 4;
  } while (uVar2 < 0x100);
  (**(code **)(unaff_ESI + 100))(uVar2,local_408);
  iVar1 = (**(code **)(unaff_ESI + 0x30))();
  if (iVar1 != 0) {
    puVar3 = local_408;
    local_40c = 0x100;
    do {
      (**(code **)(unaff_ESI + 100))(1,puVar3);
      puVar3 = puVar3 + 4;
      local_40c = local_40c + -1;
    } while (local_40c != 0);
  }
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}

