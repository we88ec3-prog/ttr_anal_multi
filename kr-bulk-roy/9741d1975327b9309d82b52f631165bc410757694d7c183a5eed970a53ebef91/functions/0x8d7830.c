
uint FUN_008d7830(void)

{
  char *pcVar1;
  int *piVar2;
  uint uVar3;
  uint in_EAX;
  int iVar4;
  int in_ECX;
  int *piVar5;
  uint *in_EDX;
  int *piVar6;
  uint uVar7;
  char *pcVar8;
  int *piVar9;
  int local_18;
  undefined **local_c;
  
  pcVar1 = (char *)(in_EAX + in_ECX);
  *in_EDX = in_EAX;
  in_EDX[2] = (uint)pcVar1;
  in_EDX[3] = 0;
  (*(code *)in_EDX[7])();
  pcVar8 = (char *)*in_EDX;
  while (pcVar8 < pcVar1) {
    pcVar8 = (char *)*in_EDX;
    if (((*pcVar8 == 'F') && (pcVar8 + 0x19 < pcVar1)) &&
       (iVar4 = _strncmp(pcVar8,"FontDirectory",0xd), iVar4 == 0)) {
      (*(code *)in_EDX[8])();
      (*(code *)in_EDX[7])();
      local_c = (undefined **)*in_EDX;
      pcVar8 = (char *)local_c;
      if (local_c < pcVar1) {
        do {
          if (((*pcVar8 == 'k') && (pcVar8 + 5 < pcVar1)) &&
             (iVar4 = _strncmp(pcVar8,"known",5), iVar4 == 0)) {
            if (pcVar8 < pcVar1) {
              (*(code *)in_EDX[8])();
              (*(code *)in_EDX[0xe])();
              if (local_18 == 3) {
                local_c = (undefined **)*in_EDX;
              }
            }
            goto LAB_008d7914;
          }
          (*(code *)in_EDX[8])();
          if (in_EDX[3] != 0) goto LAB_008d79ff;
          (*(code *)in_EDX[7])();
          pcVar8 = (char *)*in_EDX;
        } while (pcVar8 < pcVar1);
        *in_EDX = (uint)local_c;
      }
      else {
LAB_008d7914:
        *in_EDX = (uint)local_c;
      }
    }
    else if ((*pcVar8 == '/') && (pcVar8 + 2 < pcVar1)) {
      piVar9 = (int *)(pcVar8 + 1);
      *in_EDX = (uint)piVar9;
      (*(code *)in_EDX[8])();
      if (in_EDX[3] != 0) break;
      uVar7 = (int)*in_EDX - (int)piVar9;
      if ((uVar7 - 1 < 0x15) && ((char *)*in_EDX < pcVar1)) {
        local_c = &PTR_s_version_00be8358;
        do {
          piVar6 = (int *)*local_c;
          if ((piVar6 != (int *)0x0) && ((char)*piVar9 == (char)*piVar6)) {
            piVar5 = piVar6;
            do {
              iVar4 = *piVar5;
              piVar5 = (int *)((int)piVar5 + 1);
            } while ((char)iVar4 != '\0');
            piVar2 = piVar9;
            uVar3 = uVar7;
            if (uVar7 == (int)piVar5 - ((int)piVar6 + 1)) {
              for (; 3 < uVar3; uVar3 = uVar3 - 4) {
                if (*piVar2 != *piVar6) goto LAB_008d79db;
                piVar6 = piVar6 + 1;
                piVar2 = piVar2 + 1;
              }
              if ((uVar3 == 0) ||
                 (((char)*piVar6 == (char)*piVar2 &&
                  ((uVar3 < 2 ||
                   ((*(char *)((int)piVar6 + 1) == *(char *)((int)piVar2 + 1) &&
                    ((uVar3 < 3 || (*(char *)((int)piVar6 + 2) == *(char *)((int)piVar2 + 2)))))))))
                 )) {
                uVar7 = FUN_008d77b0();
                in_EDX[3] = uVar7;
                if (uVar7 != 0) {
                  return uVar7;
                }
                break;
              }
            }
          }
LAB_008d79db:
          local_c = local_c + 9;
        } while ((int)local_c < 0xbe8628);
      }
    }
    else {
      (*(code *)in_EDX[8])();
      if (in_EDX[3] != 0) break;
    }
    (*(code *)in_EDX[7])();
    pcVar8 = (char *)*in_EDX;
  }
LAB_008d79ff:
  return in_EDX[3];
}

