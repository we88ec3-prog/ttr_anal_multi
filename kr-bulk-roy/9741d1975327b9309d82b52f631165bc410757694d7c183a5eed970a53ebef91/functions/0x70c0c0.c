
void FUN_0070c0c0(int param_1)

{
  int *piVar1;
  undefined4 *puVar2;
  char *pcVar3;
  int iVar4;
  undefined4 *puVar5;
  int iVar6;
  undefined4 uVar7;
  void *_Src;
  int iVar8;
  uint _Size;
  undefined4 local_22c;
  undefined1 *local_228;
  int local_218;
  undefined1 *local_214;
  int local_210;
  int local_20c;
  undefined1 local_208 [512];
  uint local_8;
  
  local_8 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  puVar2 = (undefined4 *)(*(int *)(param_1 + 0xc) + 0x10);
  if (((puVar2 < *(undefined4 **)(param_1 + 8)) && (puVar2 != &DAT_00c0bfc8)) &&
     (0 < *(int *)(*(int *)(param_1 + 0xc) + 0x18))) {
    local_228 = (undefined1 *)FUN_006f6210(param_1);
  }
  else {
    local_22c = 0;
    local_228 = &DAT_00bf2375;
  }
  puVar2 = *(undefined4 **)(param_1 + 0xc);
  if (puVar2 < *(undefined4 **)(param_1 + 8)) {
    if ((puVar2 != &DAT_00c0bfc8) && (puVar2[2] == 5)) goto LAB_0070c179;
    if ((*(undefined4 **)(param_1 + 8) <= puVar2) ||
       ((puVar2 == &DAT_00c0bfc8 || (puVar2[2] == -1)))) goto LAB_0070c14b;
    pcVar3 = (&PTR_DAT_00c0be1c)[puVar2[2]];
  }
  else {
LAB_0070c14b:
    pcVar3 = "no value";
  }
  FUN_006f5580(param_1,"%s expected, got %s","table",pcVar3);
  FUN_006f5da0(1);
LAB_0070c179:
  puVar2 = (undefined4 *)(*(int *)(param_1 + 0xc) + 0x20);
  if (((puVar2 < *(undefined4 **)(param_1 + 8)) && (puVar2 != &DAT_00c0bfc8)) &&
     (0 < *(int *)(*(int *)(param_1 + 0xc) + 0x28))) {
    local_218 = FUN_006f6370(param_1,3);
  }
  else {
    local_218 = 1;
  }
  puVar2 = (undefined4 *)(*(int *)(param_1 + 0xc) + 0x30);
  if (((puVar2 < *(undefined4 **)(param_1 + 8)) && (puVar2 != &DAT_00c0bfc8)) &&
     (0 < *(int *)(*(int *)(param_1 + 0xc) + 0x38))) {
    iVar4 = FUN_006f6370(param_1,4);
  }
  else {
    iVar4 = FUN_006f5460();
  }
  local_214 = local_208;
  local_210 = 0;
  iVar6 = param_1;
  do {
    local_20c = iVar6;
    if (iVar4 < local_218) {
      iVar4 = (int)local_214 - (int)local_208;
      if (iVar4 != 0) {
        if (*(uint *)(*(int *)(iVar6 + 0x10) + 0x40) <= *(uint *)(*(int *)(iVar6 + 0x10) + 0x44)) {
          FUN_006fb3a0();
        }
        puVar2 = *(undefined4 **)(iVar6 + 8);
        uVar7 = FUN_006fec70(iVar6,local_208,iVar4);
        *puVar2 = uVar7;
        puVar2[2] = 4;
        *(int *)(iVar6 + 8) = *(int *)(iVar6 + 8) + 0x10;
        local_214 = local_208;
        local_210 = local_210 + 1;
      }
      iVar6 = local_20c;
      iVar4 = local_210;
      if (local_210 < 2) {
        if (local_210 == 0) {
          puVar2 = *(undefined4 **)(local_20c + 8);
          piVar1 = (int *)(local_20c + 8);
          uVar7 = FUN_006fec70(local_20c,&DAT_00bf2375,0);
          *puVar2 = uVar7;
          puVar2[2] = 4;
          *piVar1 = *piVar1 + 0x10;
        }
      }
      else {
        if (*(uint *)(*(int *)(local_20c + 0x10) + 0x40) <=
            *(uint *)(*(int *)(local_20c + 0x10) + 0x44)) {
          FUN_006fb3a0();
        }
        FUN_006fc080(iVar6,iVar4,(*(int *)(iVar6 + 8) - *(int *)(iVar6 + 0xc) >> 4) + -1);
        *(int *)(iVar6 + 8) = *(int *)(iVar6 + 8) + iVar4 * -0x10 + 0x10;
      }
      __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
      return;
    }
    puVar2 = *(undefined4 **)(param_1 + 8);
    puVar5 = (undefined4 *)FUN_006f9b70(local_218);
    *puVar2 = *puVar5;
    puVar2[1] = puVar5[1];
    puVar2[2] = puVar5[2];
    *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 0x10;
    if ((*(undefined **)(param_1 + 8) == &DAT_00c0bfd8) ||
       ((iVar6 = *(int *)(*(undefined **)(param_1 + 8) + -8), iVar6 != 4 && (iVar6 != 3)))) {
      FUN_006f5da0(1);
    }
    iVar8 = local_20c;
    iVar6 = *(int *)(local_20c + 8);
    piVar1 = (int *)(local_20c + 8);
    if (*(int *)(iVar6 + -8) == 4) {
LAB_0070c2d9:
      _Size = *(uint *)(*(int *)(iVar6 + -0x10) + 0xc);
      _Src = (void *)(*(int *)(iVar6 + -0x10) + 0x10);
    }
    else {
      iVar6 = FUN_006fb5d0();
      if (iVar6 != 0) {
        if (*(uint *)(*(int *)(iVar8 + 0x10) + 0x40) <= *(uint *)(*(int *)(iVar8 + 0x10) + 0x44)) {
          FUN_006fb3a0();
        }
        iVar6 = *piVar1;
        goto LAB_0070c2d9;
      }
      _Size = 0;
      _Src = (void *)0x0;
    }
    iVar6 = local_20c;
    if ((uint)((int)&local_8 - (int)local_214) < _Size) {
      iVar8 = (int)local_214 - (int)local_208;
      if (iVar8 != 0) {
        if (*(uint *)(*(int *)(local_20c + 0x10) + 0x40) <=
            *(uint *)(*(int *)(local_20c + 0x10) + 0x44)) {
          FUN_006fb3a0();
        }
        puVar2 = *(undefined4 **)(iVar6 + 8);
        uVar7 = FUN_006fec70(iVar6,local_208,iVar8);
        *puVar2 = uVar7;
        puVar2[2] = 4;
        *(int *)(iVar6 + 8) = *(int *)(iVar6 + 8) + 0x10;
        local_210 = local_210 + 1;
        local_214 = local_208;
        FUN_006f52b0();
      }
      local_210 = local_210 + 1;
      FUN_006f6b60(&local_214);
    }
    else {
      FID_conflict__memcpy(local_214,_Src,_Size);
      local_214 = local_214 + _Size;
      *piVar1 = *piVar1 + -0x10;
    }
    if (local_218 != iVar4) {
      FUN_006f6c40(local_228,local_22c);
    }
    local_218 = local_218 + 1;
    iVar6 = local_20c;
  } while( true );
}

