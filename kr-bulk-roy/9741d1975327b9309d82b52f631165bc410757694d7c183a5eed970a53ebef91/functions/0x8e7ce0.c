
int FUN_008e7ce0(int param_1,int *param_2)

{
  byte bVar1;
  uint uVar2;
  byte *pbVar3;
  byte *pbVar4;
  int in_EAX;
  int iVar5;
  byte *pbVar6;
  char *pcVar7;
  int in_EDX;
  undefined1 *puVar8;
  char *pcVar9;
  uint uVar10;
  bool bVar11;
  undefined1 local_20 [4];
  undefined1 local_1c [4];
  byte *local_18;
  undefined **local_14;
  byte *local_10;
  byte *local_c;
  byte local_5;
  
  pbVar6 = (byte *)(in_EAX + in_EDX);
  *param_2 = in_EAX;
  local_10 = (byte *)0x0;
  bVar11 = false;
  param_2[2] = (int)pbVar6;
  param_2[3] = 0;
  local_c = pbVar6;
  (*(code *)param_2[7])(param_2);
  if (pbVar6 <= (byte *)*param_2) {
LAB_008e8092:
    return param_2[3];
  }
LAB_008e7d12:
  pbVar6 = (byte *)*param_2;
  if (((*pbVar6 == 0x65) &&
      (((pbVar6 + 6 == local_c ||
        ((pbVar6 + 6 < local_c &&
         ((((((((bVar1 = pbVar6[5], bVar1 == 0x20 || (bVar1 == 0xd)) || (bVar1 == 10)) ||
              ((bVar1 == 9 || (bVar1 == 0xc)))) || (bVar1 == 0)) ||
            (((bVar1 == 0x2f || (bVar1 == 0x28)) ||
             ((bVar1 == 0x29 || (((bVar1 == 0x3c || (bVar1 == 0x3e)) || (bVar1 == 0x5b)))))))) ||
           ((bVar1 == 0x5d || (bVar1 == 0x7b)))) || ((bVar1 == 0x7d || (bVar1 == 0x25)))))))) &&
       (iVar5 = _strncmp((char *)pbVar6,"eexec",5), iVar5 == 0)))) ||
     ((*pbVar6 == 99 &&
      (((pbVar6 + 10 == local_c ||
        ((pbVar6 + 10 < local_c &&
         (((((bVar1 = pbVar6[9], bVar1 == 0x20 || (bVar1 == 0xd)) ||
            ((bVar1 == 10 || (((bVar1 == 9 || (bVar1 == 0xc)) || (bVar1 == 0)))))) ||
           ((bVar1 == 0x2f || (bVar1 == 0x28)))) ||
          ((bVar1 == 0x29 ||
           (((bVar1 == 0x3c || (bVar1 == 0x3e)) ||
            ((bVar1 == 0x5b ||
             ((((bVar1 == 0x5d || (bVar1 == 0x7b)) || (bVar1 == 0x7d)) || (bVar1 == 0x25))))))))))))
        )) && (iVar5 = _strncmp((char *)pbVar6,"closefile",9), iVar5 == 0)))))) goto LAB_008e8092;
  if (((*pbVar6 == 0x46) &&
      ((pbVar6 + 0xe == local_c ||
       ((pbVar6 + 0xe < local_c &&
        ((((bVar1 = pbVar6[0xd], bVar1 == 0x20 || (bVar1 == 0xd)) ||
          ((bVar1 == 10 || ((bVar1 == 9 || (bVar1 == 0xc)))))) ||
         ((((bVar1 == 0 ||
            ((((bVar1 == 0x2f || (bVar1 == 0x28)) || (bVar1 == 0x29)) ||
             (((bVar1 == 0x3c || (bVar1 == 0x3e)) ||
              ((bVar1 == 0x5b || ((bVar1 == 0x5d || (bVar1 == 0x7b)))))))))) || (bVar1 == 0x7d)) ||
          (bVar1 == 0x25)))))))))) &&
     (iVar5 = _strncmp((char *)pbVar6,"FontDirectory",0xd), iVar5 == 0)) {
    if ((param_2[0x5d] & 1U) != 0) {
      param_2[0x5d] = param_2[0x5d] | 2;
    }
    *param_2 = *param_2 + 0xd;
    goto LAB_008e807b;
  }
  bVar1 = *pbVar6;
  if (bVar1 - 0x30 < 10) {
    local_10 = pbVar6;
    (*(code *)param_2[8])(param_2);
    if (param_2[3] == 0) {
      bVar11 = true;
      goto LAB_008e807b;
    }
    goto LAB_008e8092;
  }
  if ((((bVar1 == 0x52) && (pbVar6 + 6 < local_c)) && (pbVar6[1] == 0x44)) && (bVar11)) {
    *param_2 = (int)local_10;
    iVar5 = *(int *)(*(int *)(param_1 + 0x80) + 0x30);
    puVar8 = local_1c;
LAB_008e7ec9:
    iVar5 = FUN_008e7060(&local_18,puVar8,iVar5 != 0);
    if (iVar5 == 0) {
      return 3;
    }
    goto LAB_008e8079;
  }
  if (((bVar1 == 0x2d) && (pbVar6 + 6 < local_c)) && ((pbVar6[1] == 0x7c && (bVar11)))) {
    *param_2 = (int)local_10;
    iVar5 = *(int *)(*(int *)(param_1 + 0x80) + 0x30);
    puVar8 = local_20;
    goto LAB_008e7ec9;
  }
  if ((bVar1 == 0x2f) && (pbVar6 + 2 < local_c)) {
    local_18 = pbVar6 + 1;
    *param_2 = (int)local_18;
    (*(code *)param_2[8])(param_2);
    if (param_2[3] != 0) goto LAB_008e8092;
    uVar10 = *param_2 - (int)local_18;
    if ((uVar10 - 1 < 0x15) && ((byte *)*param_2 < local_c)) {
      pcVar9 = "version";
      local_14 = &PTR_s_version_00bea228;
      local_5 = *local_18;
      do {
        if (local_5 == *pcVar9) {
          pbVar6 = (byte *)pcVar9;
          do {
            bVar1 = *pbVar6;
            pbVar6 = pbVar6 + 1;
          } while (bVar1 != 0);
          uVar2 = uVar10;
          pbVar3 = (byte *)pcVar9;
          pbVar4 = local_18;
          if (uVar10 == (int)pbVar6 - (int)(pcVar9 + 1)) {
            for (; 3 < uVar2; uVar2 = uVar2 - 4) {
              if (*(int *)pbVar4 != *(int *)pbVar3) goto LAB_008e7fe1;
              pbVar3 = pbVar3 + 4;
              pbVar4 = pbVar4 + 4;
            }
            if ((uVar2 == 0) ||
               ((*pbVar3 == *pbVar4 &&
                ((uVar2 < 2 ||
                 ((pbVar3[1] == pbVar4[1] && ((uVar2 < 3 || (pbVar3[2] == pbVar4[2])))))))))) {
              if (((uint)local_14[8] & ((param_2[0x5d] & 1U) != 0) + 1) != 0) {
                if ((param_2[0x5d] & 2U) == 0) goto LAB_008e8049;
                pcVar7 = "CharStrings";
                goto LAB_008e8020;
              }
              break;
            }
          }
        }
LAB_008e7fe1:
        pcVar9 = local_14[9];
        local_14 = local_14 + 9;
      } while ((byte *)pcVar9 != (byte *)0x0);
    }
  }
  else {
    (*(code *)param_2[8])(param_2);
    if (param_2[3] != 0) goto LAB_008e8092;
  }
LAB_008e8079:
  bVar11 = false;
LAB_008e807b:
  (*(code *)param_2[7])(param_2);
  if (local_c <= (byte *)*param_2) goto LAB_008e8092;
  goto LAB_008e7d12;
  while( true ) {
    bVar1 = pcVar9[1];
    bVar11 = bVar1 < (byte)pcVar7[1];
    if (bVar1 != pcVar7[1]) goto LAB_008e8040;
    pcVar9 = pcVar9 + 2;
    pcVar7 = pcVar7 + 2;
    if (bVar1 == 0) break;
LAB_008e8020:
    bVar1 = *pcVar9;
    bVar11 = bVar1 < (byte)*pcVar7;
    if (bVar1 != *pcVar7) {
LAB_008e8040:
      iVar5 = (1 - (uint)bVar11) - (uint)(bVar11 != 0);
      goto LAB_008e8045;
    }
    if (bVar1 == 0) break;
  }
  iVar5 = 0;
LAB_008e8045:
  if (iVar5 == 0) {
LAB_008e8049:
    iVar5 = FUN_008e6f40();
    param_2[3] = iVar5;
    if (iVar5 != 0) {
      if ((char)iVar5 != -0x5e) {
        return iVar5;
      }
      param_2[3] = 0;
    }
  }
  goto LAB_008e8079;
}

