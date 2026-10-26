
void FUN_004cc8b0(void)

{
  char cVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 **ppuVar4;
  undefined4 *puVar5;
  int unaff_ESI;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined4 *local_1c;
  undefined4 *local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  uint local_8;
  
  local_8 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  if ((*(int *)(unaff_ESI + 0x124) == 0) && (*(int *)(unaff_ESI + 0xf4) != 0)) {
    if (*(int *)(unaff_ESI + 0xf8) == 0) {
      local_1c = (undefined4 *)(uint)*(ushort *)(unaff_ESI + 0x128);
      iVar2 = FUN_0040f060();
      FUN_0082ef00(&local_1c);
      if ((local_18 == *(undefined4 **)(iVar2 + 0xc)) || ((int *)local_18[4] == (int *)0x0)) {
        local_14 = *(undefined4 *)(unaff_ESI + 0x110);
        local_10 = *(undefined4 *)(unaff_ESI + 0x114);
        local_c = *(undefined4 *)(unaff_ESI + 0x118);
      }
      else {
        puVar3 = (undefined4 *)(**(code **)(*(int *)local_18[4] + 0x4c))();
        local_14 = *puVar3;
        local_10 = puVar3[1];
        local_c = puVar3[2];
        *(undefined4 *)(unaff_ESI + 0x110) = local_14;
        *(undefined4 *)(unaff_ESI + 0x114) = local_10;
        *(undefined4 *)(unaff_ESI + 0x118) = local_c;
      }
    }
    else {
      local_14 = *(undefined4 *)(unaff_ESI + 0x128);
      local_10 = *(undefined4 *)(unaff_ESI + 300);
      local_c = 0;
      (**(code **)*DAT_00fba838)(local_14,local_10,&local_c,0);
    }
    cVar1 = *(char *)((int)DAT_00fbaae8[1] + 0xa1);
    puVar3 = (undefined4 *)DAT_00fbaae8[1];
    local_18 = DAT_00fbaae8;
    while (puVar5 = puVar3, cVar1 == '\0') {
      if (*(ushort *)(puVar5 + 3) < *(ushort *)(unaff_ESI + 0x10c)) {
        puVar3 = (undefined4 *)puVar5[2];
        puVar5 = local_18;
      }
      else {
        puVar3 = (undefined4 *)*puVar5;
      }
      cVar1 = *(char *)((int)puVar3 + 0xa1);
      local_18 = puVar5;
    }
    if ((local_18 == DAT_00fbaae8) || (*(ushort *)(unaff_ESI + 0x10c) < *(ushort *)(local_18 + 3)))
    {
      local_1c = DAT_00fbaae8;
      ppuVar4 = &local_1c;
    }
    else {
      ppuVar4 = &local_18;
    }
    if (*ppuVar4 != DAT_00fbaae8) {
      uVar8 = 0x3f800000;
      puVar3 = &local_14;
      uVar7 = 0;
      uVar6 = 0;
      FUN_0049b140(0,puVar3,0,0x3f800000);
      FUN_00551f20(uVar6,puVar3,uVar7,uVar8);
    }
    *(undefined4 *)(unaff_ESI + 0x124) = 1;
  }
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}

