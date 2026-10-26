
undefined4 FUN_0052c290(void)

{
  int iVar1;
  char *_Str1;
  int iVar2;
  uint uVar3;
  uint *puVar4;
  undefined4 *puVar5;
  uint *unaff_ESI;
  int iVar6;
  undefined1 local_28 [16];
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  
  local_18 = 0;
  local_14 = 0;
  local_c = 0;
  local_10 = 1;
  iVar1 = FUN_0072e360();
  do {
    if (iVar1 == 0) {
      if ((unaff_ESI[2] == 0 && unaff_ESI[3] == 0) && (*unaff_ESI == 0 && unaff_ESI[1] == 0)) {
        return 0;
      }
      return 1;
    }
    iVar6 = *(int *)(iVar1 + 0x94);
    if (iVar6 != iVar1 + 0x44) {
      do {
        _Str1 = (char *)(iVar6 + 0x14);
        if (0xf < *(uint *)(iVar6 + 0x28)) {
          _Str1 = *(char **)_Str1;
        }
        iVar2 = __stricmp(_Str1,"STATUS");
        if (iVar2 == 0) {
          if (iVar6 != 0) {
            puVar5 = (undefined4 *)(iVar6 + 0x30);
            if (0xf < *(uint *)(iVar6 + 0x44)) {
              puVar5 = (undefined4 *)*puVar5;
            }
            if (puVar5 != (undefined4 *)0x0) {
              uVar3 = FUN_008917b4(puVar5);
              goto LAB_0052c2f9;
            }
          }
          break;
        }
        iVar6 = *(int *)(iVar6 + 0x50);
      } while (iVar6 != iVar1 + 0x44);
    }
    uVar3 = 0;
LAB_0052c2f9:
    puVar4 = (uint *)FUN_0052ead0(local_28,(uVar3 & 0xff) - 1);
    unaff_ESI[2] = unaff_ESI[2] | puVar4[2];
    unaff_ESI[3] = unaff_ESI[3] | puVar4[3];
    *unaff_ESI = *unaff_ESI | *puVar4;
    unaff_ESI[1] = unaff_ESI[1] | puVar4[1];
    iVar1 = FUN_0072e3c0();
  } while( true );
}

