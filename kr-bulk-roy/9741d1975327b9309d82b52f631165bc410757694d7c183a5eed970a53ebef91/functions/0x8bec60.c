
int FUN_008bec60(char *param_1,char *param_2)

{
  char cVar1;
  uint uVar2;
  undefined *puVar3;
  int in_EAX;
  int iVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 *puVar7;
  undefined **ppuVar8;
  int iVar9;
  int local_c;
  int local_8;
  
  uVar5 = *(undefined4 *)(in_EAX + 0x44088);
  local_8 = 0;
  iVar4 = FUN_008bdf60(*(undefined4 *)(in_EAX + 0x80));
  if (iVar4 == 0) {
    local_c = FUN_008bdf60(in_EAX + 0x44094);
    if (local_c == 0) {
      local_8 = FUN_008be830(param_1,1);
      if (local_8 != 0) {
        return local_8;
      }
      local_c = FUN_008bdf60(in_EAX + 0x44094);
    }
    iVar4 = *(int *)(in_EAX + 0x48);
    if (*(int *)(in_EAX + 0x4c) == iVar4) {
      if (iVar4 == 0) {
        iVar9 = 1;
        uVar6 = 0;
      }
      else {
        uVar6 = *(undefined4 *)(in_EAX + 0x50);
        iVar9 = iVar4 + 1;
      }
      uVar6 = FUN_008bc7d0(uVar5,0x10,iVar4,iVar9,uVar6,&local_8);
      *(undefined4 *)(in_EAX + 0x50) = uVar6;
      if (local_8 != 0) {
        return local_8;
      }
      puVar7 = (undefined4 *)(*(int *)(in_EAX + 0x48) * 0x10 + *(int *)(in_EAX + 0x50));
      *puVar7 = 0;
      puVar7[1] = 0;
      puVar7[2] = 0;
      puVar7[3] = 0;
      *(int *)(in_EAX + 0x48) = *(int *)(in_EAX + 0x48) + 1;
    }
    uVar2 = *(uint *)(local_c + 4);
    if (uVar2 < 0x53) {
      ppuVar8 = &PTR_s_ADD_STYLE_NAME_00bd74f0 + uVar2 * 4;
    }
    else {
      ppuVar8 = (undefined **)((uVar2 - 0x53) * 0x10 + *(int *)(in_EAX + 0x4408c));
    }
    puVar7 = (undefined4 *)(*(int *)(in_EAX + 0x4c) * 0x10 + *(int *)(in_EAX + 0x50));
    *puVar7 = *ppuVar8;
    puVar7[1] = ppuVar8[1];
    puVar7[2] = ppuVar8[2];
    puVar3 = ppuVar8[1];
    if (puVar3 == (undefined *)0x1) {
      puVar7[3] = 0;
      if ((param_2 != (char *)0x0) && (*param_2 != '\0')) {
        uVar6 = FUN_008ba000(uVar5,param_2,&local_8);
        puVar7[3] = uVar6;
        if (local_8 != 0) {
          return local_8;
        }
      }
    }
    else if (puVar3 == (undefined *)0x2) {
      uVar6 = FUN_008be600(0,10);
      puVar7[3] = uVar6;
    }
    else if (puVar3 == (undefined *)0x3) {
      uVar6 = FUN_008be520(0,10);
      puVar7[3] = uVar6;
    }
    iVar4 = _strncmp(param_1,"COMMENT",7);
    if ((iVar4 != 0) && (local_8 = FUN_008bded0(*(undefined4 *)(in_EAX + 0x4c),uVar5), local_8 != 0)
       ) {
      return local_8;
    }
    *(int *)(in_EAX + 0x4c) = *(int *)(in_EAX + 0x4c) + 1;
    iVar4 = _strncmp(param_1,"DEFAULT_CHAR",0xc);
    if (iVar4 == 0) {
      *(undefined4 *)(in_EAX + 0x24) = puVar7[3];
      return local_8;
    }
    iVar4 = _strncmp(param_1,"FONT_ASCENT",0xb);
    if (iVar4 == 0) {
      *(undefined4 *)(in_EAX + 0x28) = puVar7[3];
      return local_8;
    }
    iVar4 = _strncmp(param_1,"FONT_DESCENT",0xc);
    if (iVar4 == 0) {
      *(undefined4 *)(in_EAX + 0x2c) = puVar7[3];
      return local_8;
    }
    iVar4 = _strncmp(param_1,"SPACING",7);
    if (iVar4 == 0) {
      if ((char *)puVar7[3] == (char *)0x0) {
        return 3;
      }
      cVar1 = *(char *)puVar7[3];
      if ((cVar1 == 'p') || (cVar1 == 'P')) {
        *(undefined4 *)(in_EAX + 0x1c) = 8;
      }
      else {
        if ((cVar1 == 'm') || (cVar1 == 'M')) {
          *(undefined4 *)(in_EAX + 0x1c) = 0x10;
          return local_8;
        }
        if ((cVar1 == 'c') || (cVar1 == 'C')) {
          *(undefined4 *)(in_EAX + 0x1c) = 0x20;
          return local_8;
        }
      }
    }
  }
  else {
    iVar9 = *(int *)(iVar4 + 4) * 0x10 + *(int *)(in_EAX + 0x50);
    iVar4 = *(int *)(iVar9 + 4);
    if (iVar4 == 1) {
      FUN_008b9f80(uVar5,*(undefined4 *)(iVar9 + 0xc));
      *(undefined4 *)(iVar9 + 0xc) = 0;
      if ((param_2 != (char *)0x0) && (*param_2 != '\0')) {
        uVar5 = FUN_008ba000(uVar5,param_2,&local_8);
        *(undefined4 *)(iVar9 + 0xc) = uVar5;
        return local_8;
      }
    }
    else {
      if (iVar4 == 2) {
        uVar5 = FUN_008be600(0,10);
        *(undefined4 *)(iVar9 + 0xc) = uVar5;
        return local_8;
      }
      if (iVar4 == 3) {
        uVar5 = FUN_008be520(0,10);
        *(undefined4 *)(iVar9 + 0xc) = uVar5;
        return local_8;
      }
    }
  }
  return local_8;
}

