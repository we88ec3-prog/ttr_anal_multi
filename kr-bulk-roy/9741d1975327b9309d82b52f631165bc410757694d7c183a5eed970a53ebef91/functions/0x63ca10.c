
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0063ca10(void)

{
  short sVar1;
  code *pcVar2;
  uint uVar3;
  short *psVar4;
  short *psVar5;
  undefined4 *puVar6;
  int in_ECX;
  uint uVar7;
  int in_EDX;
  int iVar8;
  int iVar9;
  undefined2 local_90 [8];
  undefined4 local_80;
  undefined2 *local_7c;
  undefined4 *puStack_78;
  undefined2 local_74;
  undefined4 local_64;
  undefined4 local_60;
  undefined4 uStack_5c;
  undefined4 *puStack_58;
  undefined4 local_3c;
  undefined4 local_38;
  undefined1 *local_34;
  uint local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0093dbbc;
  local_10 = ExceptionList;
  local_14 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  iVar9 = *(int *)(in_EDX + 8);
  if (iVar9 == *(int *)(*(int *)(in_ECX + 0xf0) + 0x20)) {
    iVar9 = *(int *)(*(int *)(in_ECX + 0xec) + 0xcc);
    if (iVar9 != 0) {
      iVar9 = *(int *)(iVar9 + 0xdc);
      if (iVar9 == 0) {
        iVar9 = -1;
      }
      else {
        iVar9 = *(int *)(iVar9 + 0x20);
      }
      if (iVar9 != -1) {
        if ((_DAT_00fd94dc & 1) == 0) {
          _DAT_00fd94dc = _DAT_00fd94dc | 1;
          FUN_004f10f0();
          puStack_58 = (undefined4 *)0x63caa1;
          _atexit((_func_4879 *)&LAB_00bce260);
        }
        uVar7 = DAT_00fdf390 - DAT_00fdf38c >> 2;
        uVar3 = 0;
        if (uVar7 != 0) {
          do {
            iVar8 = *(int *)(DAT_00fdf38c + uVar3 * 4);
            if (*(int *)(iVar8 + 8) == iVar9) {
              if (iVar8 != 0) {
                local_38 = *(undefined4 *)(iVar8 + 4);
                goto LAB_0063cad2;
              }
              break;
            }
            uVar3 = uVar3 + 1;
          } while (uVar3 < uVar7);
        }
        local_38 = 0;
LAB_0063cad2:
        if ((DAT_00faadd4 & 1) == 0) {
          DAT_00faadd4 = DAT_00faadd4 | 1;
          local_8 = 0;
          FUN_00587480();
          puStack_58 = (undefined4 *)0x63caf4;
          _atexit((_func_4879 *)&LAB_00bcccc0);
          local_8 = 0xffffffff;
        }
        puStack_58 = (undefined4 *)0x63cb05;
        puStack_58 = (undefined4 *)FUN_00891268();
        if (puStack_58 == (undefined4 *)0x0) {
          puStack_58 = (undefined4 *)0x0;
        }
        else {
          puStack_58[1] = 0xffffffff;
          puStack_58[2] = 0xffffffff;
          puStack_58[3] = 0;
          puStack_58[4] = 0xf43c3;
          *puStack_58 = FoxUI::FXUIEventI1::vftable;
          puStack_58[5] = iVar9;
        }
        puStack_78 = (undefined4 *)0x0;
        local_60 = 7;
        local_64 = 0;
        local_7c = &DAT_00bed1fc;
        local_74 = 0;
        local_80 = 0x63cb61;
        FUN_00402160();
        local_8 = 1;
        local_3c = 0xa3;
        puStack_78 = (undefined4 *)0x63cb74;
        iVar9 = FUN_005854b0();
        puStack_78 = &local_3c;
        local_7c = (undefined2 *)0x63cb84;
        FUN_005740f0();
        if (local_34 == *(undefined1 **)(iVar9 + 4)) {
          pcVar2 = (code *)swi(3);
          (*pcVar2)();
          return;
        }
        puStack_78 = (undefined4 *)0x63cbac;
        psVar4 = (short *)FUN_004ed610();
        local_8._0_1_ = 2;
        if (7 < *(uint *)(psVar4 + 10)) {
          psVar4 = *(short **)psVar4;
        }
        local_34 = (undefined1 *)local_90;
        local_7c = (undefined2 *)0x7;
        local_80 = 0;
        local_90[0] = 0;
        psVar5 = psVar4;
        do {
          sVar1 = *psVar5;
          psVar5 = psVar5 + 1;
        } while (sVar1 != 0);
        FUN_00402160(psVar4,(int)psVar5 - (int)(psVar4 + 1) >> 1);
        local_8 = CONCAT31(local_8._1_3_,3);
        FUN_0058b270(0xcf);
        if (7 < local_1c) {
          puStack_58 = (undefined4 *)0x63cc0e;
          FUN_0089120c();
        }
      }
    }
  }
  else if (iVar9 == *(int *)(*(int *)(in_ECX + 0xf4) + 0x20)) {
    if ((DAT_00faadd4 & 1) == 0) {
      DAT_00faadd4 = DAT_00faadd4 | 1;
      local_8 = 4;
      FUN_00587480();
      puStack_58 = (undefined4 *)0x63cc4a;
      _atexit((_func_4879 *)&LAB_00bcccc0);
    }
    local_8 = 0xffffffff;
    puStack_58 = (undefined4 *)0x63cc5e;
    FUN_0058aad0();
  }
  else if (iVar9 == *(int *)(*(int *)(in_ECX + 0xf8) + 0x20)) {
    iVar9 = *(int *)(*(int *)(in_ECX + 0xec) + 0xcc);
    if (iVar9 != 0) {
      iVar9 = *(int *)(iVar9 + 0xdc);
      iVar8 = -1;
      if (iVar9 != 0) {
        iVar8 = *(int *)(iVar9 + 0x20);
      }
      if (iVar8 != -1) {
        puStack_58 = (undefined4 *)0x63cca6;
        puVar6 = (undefined4 *)FUN_00891268();
        if (puVar6 == (undefined4 *)0x0) {
          FUN_004072a0();
        }
        else {
          puVar6[5] = iVar8;
          puVar6[1] = 0xffffffff;
          puVar6[2] = 0xffffffff;
          puVar6[3] = 0;
          puVar6[4] = 0xf4378;
          *puVar6 = FoxUI::FXUIEventI1::vftable;
          FUN_004072a0();
        }
      }
    }
  }
  else if (iVar9 == *(int *)(*(int *)(in_ECX + 0xfc) + 0x20)) {
    if ((*(uint *)(*(int *)(in_ECX + 0xfc) + 0x28) >> 9 & 1) == 0) {
      *(uint *)(in_ECX + 0x104) = *(uint *)(in_ECX + 0x104) & 0xfffffffe;
      puStack_58 = *(undefined4 **)(in_ECX + 0x108);
    }
    else {
      *(uint *)(in_ECX + 0x104) = *(uint *)(in_ECX + 0x104) | 1;
      puStack_58 = *(undefined4 **)(in_ECX + 0x108);
    }
    uStack_5c = 0x63cd24;
    FUN_0063ceb0();
  }
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

