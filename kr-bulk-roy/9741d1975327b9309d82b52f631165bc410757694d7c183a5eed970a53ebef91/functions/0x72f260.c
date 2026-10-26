
void FUN_0072f260(undefined4 param_1)

{
  char cVar1;
  char cVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined **ppuVar5;
  char *pcVar6;
  int iVar7;
  int iVar8;
  uint uVar9;
  int in_ECX;
  int *in_EDX;
  undefined **local_418;
  char acStack_412 [2];
  undefined2 local_410;
  char local_40e [1026];
  uint local_c;
  
  local_c = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  if (in_EDX == (int *)0x0) {
    if (*(char *)(in_ECX + 0x44) == '\0') {
      *(undefined1 *)(in_ECX + 0x44) = 1;
      *(undefined4 *)(in_ECX + 0x48) = 2;
      pcVar6 = PTR_s_Failed_to_open_file_00d63c90;
      do {
        cVar1 = *pcVar6;
        pcVar6 = pcVar6 + 1;
      } while (cVar1 != '\0');
      FUN_00402a70(PTR_s_Failed_to_open_file_00d63c90,
                   (int)pcVar6 - (int)(PTR_s_Failed_to_open_file_00d63c90 + 1));
      *(undefined4 *)(in_ECX + 0x70) = 0xffffffff;
      *(undefined4 *)(in_ECX + 0x6c) = 0xffffffff;
      local_418 = TiXmlErrorReporter::vftable;
      FUN_00731de0(&local_418,0,0,0);
    }
    __security_check_cookie(local_c ^ (uint)&stack0xfffffffc);
    return;
  }
  puVar3 = *(undefined4 **)(in_ECX + 0x18);
  while (puVar3 != (undefined4 *)0x0) {
    puVar4 = (undefined4 *)*puVar3;
    puVar3 = (undefined4 *)puVar3[0x10];
    (*(code *)*puVar4)(1);
  }
  *(undefined4 *)(in_ECX + 0x18) = 0;
  *(undefined4 *)(in_ECX + 0x1c) = 0;
  *(undefined4 *)(in_ECX + 8) = 0xffffffff;
  *(undefined4 *)(in_ECX + 4) = 0xffffffff;
  (**(code **)(*in_EDX + 0x34))(0,2);
  iVar7 = (**(code **)(*in_EDX + 0x30))();
  (**(code **)(*in_EDX + 0x34))(0,0);
  if (iVar7 != 0) {
    pcVar6 = (char *)FUN_0087dc3d(iVar7 + 1);
    *pcVar6 = '\0';
    iVar8 = (**(code **)(*in_EDX + 0x10))(pcVar6,iVar7,1);
    if (iVar8 == 1) {
      pcVar6[iVar7] = '\0';
      if ((*pcVar6 == 'E') && (pcVar6[1] == 'X')) {
        iVar7 = *(int *)(pcVar6 + 0xc);
        local_418 = (undefined **)FUN_0087dc3d(*(undefined4 *)(pcVar6 + 8));
        if (pcVar6[2] == '\x01') {
          local_410 = 0xe730;
          _memset(local_40e,0,0x3fe);
          iVar8 = 2;
          do {
            cVar1 = acStack_412[iVar8];
            cVar2 = acStack_412[iVar8 + 1];
            local_40e[iVar8 + -2] = cVar1 + cVar2 + '\x13';
            if (iVar8 == 0x17c) {
              local_40e[0x17a] = cVar1 + cVar2 + -0x43;
            }
            cVar1 = acStack_412[iVar8 + 1];
            local_40e[iVar8 + -1] = cVar1 + local_40e[iVar8 + -2] + '\x13';
            if (iVar8 == 0x17b) {
              local_40e[0x17a] = cVar1 + local_40e[iVar8 + -2] + -0x43;
            }
            iVar8 = iVar8 + 2;
          } while (iVar8 < 0x400);
          uVar9 = 0;
          if (0 < *(int *)(pcVar6 + 4)) {
            do {
              pcVar6[uVar9 + iVar7] = pcVar6[uVar9 + iVar7] ^ local_40e[(uVar9 & 0x3ff) - 2];
              uVar9 = uVar9 + 1;
            } while ((int)uVar9 < *(int *)(pcVar6 + 4));
          }
        }
        FUN_00727190(local_418);
        ppuVar5 = local_418;
        acStack_412[1] = FUN_0072efc0(in_ECX,*(undefined4 *)(pcVar6 + 8),param_1);
        FUN_00891d3d(ppuVar5);
      }
      else {
        acStack_412[1] = FUN_0072efc0(in_ECX,iVar7,param_1);
      }
      FUN_00891d3d(pcVar6);
      __security_check_cookie(local_c ^ (uint)&stack0xfffffffc);
      return;
    }
    FUN_00891d3d(pcVar6);
    FUN_00732010(2,0,0,0);
    __security_check_cookie(local_c ^ (uint)&stack0xfffffffc);
    return;
  }
  if (*(char *)(in_ECX + 0x44) == '\0') {
    *(undefined1 *)(in_ECX + 0x44) = 1;
    *(undefined4 *)(in_ECX + 0x48) = 0xd;
    pcVar6 = PTR_s_Error_document_empty__00d63cbc;
    do {
      cVar1 = *pcVar6;
      pcVar6 = pcVar6 + 1;
    } while (cVar1 != '\0');
    FUN_00402a70(PTR_s_Error_document_empty__00d63cbc,
                 (int)pcVar6 - (int)(PTR_s_Error_document_empty__00d63cbc + 1));
    *(undefined4 *)(in_ECX + 0x70) = 0xffffffff;
    *(undefined4 *)(in_ECX + 0x6c) = 0xffffffff;
    local_418 = TiXmlErrorReporter::vftable;
    FUN_00731de0(&local_418,0,0,0);
  }
  __security_check_cookie(local_c ^ (uint)&stack0xfffffffc);
  return;
}

