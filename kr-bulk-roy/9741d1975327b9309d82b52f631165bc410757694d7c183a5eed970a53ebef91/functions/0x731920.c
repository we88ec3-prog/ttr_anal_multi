
char * FUN_00731920(char *param_1,undefined4 *param_2,int param_3)

{
  char cVar1;
  char *pcVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  undefined **in_ECX;
  char *pcVar6;
  undefined **local_1c;
  undefined *local_18;
  undefined *local_14;
  char *local_10;
  undefined *local_c;
  
  *(undefined1 *)(in_ECX + 0x11) = 0;
  in_ECX[0x12] = (undefined *)0x0;
  local_1c = in_ECX;
  FUN_00402a70(&DAT_00bf2375,0);
  in_ECX[0x1c] = (undefined *)0x0;
  in_ECX[0x1b] = (undefined *)0x0;
  if ((param_1 == (char *)0x0) || (*param_1 == '\0')) {
    if (*(char *)(in_ECX + 0x11) == '\0') {
      *(undefined1 *)(in_ECX + 0x11) = 1;
      in_ECX[0x12] = (undefined *)0xd;
      pcVar2 = PTR_s_Error_document_empty__00d63cbc;
      do {
        cVar1 = *pcVar2;
        pcVar2 = pcVar2 + 1;
      } while (cVar1 != '\0');
      FUN_00402a70(PTR_s_Error_document_empty__00d63cbc,
                   (int)pcVar2 - (int)(PTR_s_Error_document_empty__00d63cbc + 1));
      in_ECX[0x1c] = (undefined *)0xffffffff;
      in_ECX[0x1b] = (undefined *)0xffffffff;
      local_1c = TiXmlErrorReporter::vftable;
      FUN_00731de0(&local_1c,0,0,0);
    }
    return (char *)0x0;
  }
  in_ECX[2] = (undefined *)0xffffffff;
  in_ECX[1] = (undefined *)0xffffffff;
  if (param_2 == (undefined4 *)0x0) {
    in_ECX[1] = (undefined *)0x0;
    in_ECX[2] = (undefined *)0x0;
  }
  else {
    in_ECX[1] = (undefined *)*param_2;
    in_ECX[2] = (undefined *)param_2[1];
  }
  local_c = in_ECX[0x1a];
  local_18 = in_ECX[1];
  local_14 = in_ECX[2];
  local_10 = param_1;
  in_ECX[1] = local_18;
  in_ECX[2] = local_14;
  if (((((param_3 != 2) && (*param_1 != '\0')) && (*param_1 == -0x11)) &&
      ((param_1[1] != '\0' && (param_1[1] == -0x45)))) &&
     ((param_1[2] != '\0' && (param_1[2] == -0x41)))) {
    param_3 = 1;
    *(undefined1 *)(in_ECX + 0x1d) = 1;
  }
  pcVar2 = (char *)FUN_00731170(param_3);
  if (pcVar2 == (char *)0x0) {
    FUN_00732010(0xd,0,0,0);
    return (char *)0x0;
  }
  do {
    if ((*pcVar2 == '\0') ||
       (piVar3 = (int *)FUN_007320a0(in_ECX,pcVar2,param_3), in_ECX = local_1c, piVar3 == (int *)0x0
       )) break;
    (**(code **)(*piVar3 + 8))(pcVar2,&local_18,param_3);
    FUN_0072e0d0();
    if ((param_3 == 0) && (iVar4 = (**(code **)(*piVar3 + 0x34))(), iVar4 != 0)) {
      iVar4 = (**(code **)(*piVar3 + 0x34))();
      pcVar2 = (char *)(iVar4 + 0x60);
      if (0xf < *(uint *)(iVar4 + 0x74)) {
        pcVar2 = *(char **)pcVar2;
      }
      if (*pcVar2 == '\0') {
        param_3 = 1;
      }
      else {
        pcVar6 = "UTF-8";
        do {
          if (*pcVar6 == '\0') goto LAB_00731ab9;
          iVar4 = _tolower((int)(pcVar2 + -0xc1a864)[(int)pcVar6]);
          iVar5 = _tolower((int)*pcVar6);
        } while ((iVar4 == iVar5) &&
                (pcVar6 = pcVar6 + 1, (pcVar2 + -0xc1a864)[(int)pcVar6] != '\0'));
        if (*pcVar6 == '\0') {
LAB_00731ab9:
          param_3 = 1;
        }
        else {
          pcVar6 = "UTF8";
          if (*pcVar2 != '\0') {
            do {
              if (*pcVar6 == '\0') goto LAB_00731afd;
              iVar4 = _tolower((int)(pcVar2 + -0xc44f94)[(int)pcVar6]);
              iVar5 = _tolower((int)*pcVar6);
            } while ((iVar4 == iVar5) &&
                    (pcVar6 = pcVar6 + 1, (pcVar2 + -0xc44f94)[(int)pcVar6] != '\0'));
            if (*pcVar6 == '\0') {
LAB_00731afd:
              param_3 = 1;
              goto LAB_00731b09;
            }
          }
          param_3 = 2;
        }
      }
    }
LAB_00731b09:
    pcVar2 = (char *)FUN_00731170(param_3);
    in_ECX = local_1c;
  } while (pcVar2 != (char *)0x0);
  if (in_ECX[6] == (undefined *)0x0) {
    FUN_00732010(0xd,0,0,param_3);
    return (char *)0x0;
  }
  return pcVar2;
}

