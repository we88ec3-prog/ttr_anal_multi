
void FUN_0070ed10(void)

{
  undefined2 uVar1;
  int in_EAX;
  undefined4 uVar2;
  undefined4 *puVar3;
  int iVar4;
  int extraout_ECX;
  uint uVar5;
  int iVar6;
  int *piVar7;
  ulonglong uVar8;
  int local_24 [2];
  undefined4 local_1c;
  int *local_14;
  int local_10;
  undefined4 local_c;
  int local_8;
  
  local_14 = *(int **)(in_EAX + 0x30);
  local_8 = *local_14;
  iVar6 = 0;
  *(undefined1 *)(local_8 + 0x4a) = 0;
  if (*(int *)(in_EAX + 0x10) == 0x29) {
LAB_0070eee2:
    piVar7 = local_14;
    FUN_0070dad0();
    *(byte *)(local_8 + 0x49) = *(char *)((int)piVar7 + 0x32) - (*(byte *)(local_8 + 0x4a) & 1);
    uVar5 = (uint)*(byte *)((int)piVar7 + 0x32);
    iVar6 = *piVar7;
    iVar4 = piVar7[9] + uVar5;
    uVar8 = (ulonglong)CONCAT14(*(byte *)((int)piVar7 + 0x32),iVar4);
    if (iVar4 <= (int)(uint)*(byte *)(iVar6 + 0x4b)) goto LAB_0070ef49;
    if (0xf9 < iVar4) {
                    /* WARNING: Subroutine does not return */
      FUN_006ff130(piVar7[3],"function or expression too complex",*(undefined4 *)(piVar7[3] + 0x10))
      ;
    }
  }
  else {
    while (*(int *)(in_EAX + 0x10) != 0x117) {
      if (*(int *)(in_EAX + 0x10) != 0x11d) {
                    /* WARNING: Subroutine does not return */
        FUN_006ff130();
      }
      FUN_0070d950();
      piVar7 = *(int **)(in_EAX + 0x30);
      if (200 < (int)(*(byte *)((int)piVar7 + 0x32) + 1 + iVar6)) goto LAB_0070ef37;
      uVar1 = FUN_0070da10();
      *(undefined2 *)((int)piVar7 + ((uint)*(byte *)((int)piVar7 + 0x32) + iVar6) * 2 + 0xac) =
           uVar1;
      iVar6 = iVar6 + 1;
      if ((*(char *)(local_8 + 0x4a) != '\0') || (*(int *)(in_EAX + 0x10) != 0x2c))
      goto LAB_0070eee2;
      *(undefined4 *)(in_EAX + 8) = *(undefined4 *)(in_EAX + 4);
      if (*(int *)(in_EAX + 0x20) == 0x11f) {
        uVar2 = FUN_006ffec0(in_EAX + 0x18);
        *(undefined4 *)(in_EAX + 0x10) = uVar2;
      }
      else {
        *(undefined4 *)(in_EAX + 0x10) = *(undefined4 *)(in_EAX + 0x20);
        *(undefined4 *)(in_EAX + 0x14) = *(undefined4 *)(in_EAX + 0x24);
        *(undefined4 *)(in_EAX + 0x18) = *(undefined4 *)(in_EAX + 0x28);
        *(undefined4 *)(in_EAX + 0x1c) = *(undefined4 *)(in_EAX + 0x2c);
        *(undefined4 *)(in_EAX + 0x20) = 0x11f;
      }
    }
    *(undefined4 *)(in_EAX + 8) = *(undefined4 *)(in_EAX + 4);
    if (*(int *)(in_EAX + 0x20) == 0x11f) {
      uVar2 = FUN_006ffec0(in_EAX + 0x18);
      *(undefined4 *)(in_EAX + 0x10) = uVar2;
    }
    else {
      *(undefined4 *)(in_EAX + 0x10) = *(undefined4 *)(in_EAX + 0x20);
      *(undefined4 *)(in_EAX + 0x14) = *(undefined4 *)(in_EAX + 0x24);
      *(undefined4 *)(in_EAX + 0x18) = *(undefined4 *)(in_EAX + 0x28);
      *(undefined4 *)(in_EAX + 0x1c) = *(undefined4 *)(in_EAX + 0x2c);
      *(undefined4 *)(in_EAX + 0x20) = 0x11f;
    }
    local_c = *(undefined4 *)(in_EAX + 0x34);
    local_10 = FUN_006fec70(local_c,&DAT_00c43fa8,3);
    iVar4 = *(int *)(*(int *)(in_EAX + 0x30) + 4);
    for (puVar3 = (undefined4 *)
                  (((1 << (*(byte *)(iVar4 + 7) & 0x1f)) - 1U & *(uint *)(local_10 + 8)) * 0x20 +
                  *(int *)(iVar4 + 0x10)); puVar3 != (undefined4 *)0x0;
        puVar3 = (undefined4 *)puVar3[7]) {
      if ((puVar3[6] == 4) && (puVar3[4] == local_10)) {
        if (puVar3 != &DAT_00c0bfc8) goto LAB_0070ee96;
        break;
      }
    }
    local_1c = 4;
    local_24[0] = local_10;
    puVar3 = (undefined4 *)FUN_006f9a60(local_c,iVar4,local_24);
LAB_0070ee96:
    if (puVar3[2] == 0) {
      *puVar3 = 1;
      puVar3[2] = 1;
    }
    piVar7 = *(int **)(in_EAX + 0x30);
    if ((int)(*(byte *)((int)piVar7 + 0x32) + 1 + iVar6) < 0xc9) {
      uVar1 = FUN_0070da10();
      *(undefined2 *)((int)piVar7 + ((uint)*(byte *)((int)piVar7 + 0x32) + iVar6) * 2 + 0xac) =
           uVar1;
      *(undefined1 *)(local_8 + 0x4a) = 7;
      goto LAB_0070eee2;
    }
LAB_0070ef37:
    uVar8 = FUN_0070d7c0();
    iVar6 = extraout_ECX;
  }
  uVar5 = (uint)(uVar8 >> 0x20);
  *(char *)(iVar6 + 0x4b) = (char)uVar8;
LAB_0070ef49:
  piVar7[9] = piVar7[9] + uVar5;
  return;
}

