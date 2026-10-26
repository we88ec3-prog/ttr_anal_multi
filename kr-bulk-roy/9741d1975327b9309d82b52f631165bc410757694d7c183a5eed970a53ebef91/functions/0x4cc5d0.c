
void FUN_004cc5d0(void)

{
  char cVar1;
  undefined4 *puVar2;
  undefined4 **ppuVar3;
  int in_ECX;
  undefined4 *puVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 *local_1c;
  undefined4 *local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  uint local_8;
  
  local_8 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  if ((*(int *)(in_ECX + 0xf4) != 0) && (*(int *)(in_ECX + 0xf8) != 0)) {
    local_14 = *(undefined4 *)(in_ECX + 0x128);
    local_10 = *(undefined4 *)(in_ECX + 300);
    local_c = 0;
    (**(code **)*DAT_00fba838)(local_14,local_10,&local_c,0);
    cVar1 = *(char *)((int)DAT_00fbaae8[1] + 0xa1);
    puVar2 = (undefined4 *)DAT_00fbaae8[1];
    local_1c = DAT_00fbaae8;
    while (puVar4 = puVar2, cVar1 == '\0') {
      if (*(ushort *)(puVar4 + 3) < *(ushort *)(in_ECX + 0x10c)) {
        puVar2 = (undefined4 *)puVar4[2];
        puVar4 = local_1c;
      }
      else {
        puVar2 = (undefined4 *)*puVar4;
      }
      cVar1 = *(char *)((int)puVar2 + 0xa1);
      local_1c = puVar4;
    }
    if ((local_1c == DAT_00fbaae8) || (*(ushort *)(in_ECX + 0x10c) < *(ushort *)(local_1c + 3))) {
      local_18 = DAT_00fbaae8;
      ppuVar3 = &local_18;
    }
    else {
      ppuVar3 = &local_1c;
    }
    if (*ppuVar3 != DAT_00fbaae8) {
      uVar7 = 0x3f800000;
      uVar6 = 0;
      uVar5 = 0;
      FUN_0049b140(0,0,0x3f800000);
      uVar5 = FUN_00551f90(uVar5,uVar6,uVar7);
      *(undefined4 *)(in_ECX + 0xfc) = uVar5;
    }
  }
  FUN_004caf10();
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}

