
int FUN_008db630(int param_1)

{
  char *pcVar1;
  char cVar2;
  int in_EAX;
  int iVar3;
  char *pcVar4;
  char *in_ECX;
  int iVar5;
  undefined4 *unaff_EBX;
  char *pcVar6;
  char *pcVar7;
  undefined **local_c;
  
  pcVar1 = in_ECX + in_EAX;
  *unaff_EBX = in_ECX;
  unaff_EBX[2] = pcVar1;
  unaff_EBX[3] = 0;
LAB_008db650:
  do {
    *unaff_EBX = in_ECX;
    (*(code *)unaff_EBX[7])();
    if ((char *)*unaff_EBX < pcVar1) {
      pcVar6 = (char *)*unaff_EBX + -0x11;
    }
    else {
      pcVar6 = pcVar1 + -0x12;
    }
    for (; in_ECX < pcVar6; in_ECX = in_ECX + 1) {
      if (((*in_ECX == '%') && (iVar3 = _strncmp(in_ECX,"%ADOBeginFontDict",0x11), iVar3 == 0)) &&
         (0 < *(int *)(param_1 + 300))) {
        unaff_EBX[0x18] = unaff_EBX[0x18] + 1;
      }
    }
    pcVar6 = (char *)*unaff_EBX;
    if (pcVar1 <= pcVar6) {
LAB_008db779:
      return unaff_EBX[3];
    }
    (*(code *)unaff_EBX[8])();
    if ((pcVar1 <= (char *)*unaff_EBX) || (unaff_EBX[3] != 0)) goto LAB_008db779;
    if ((*pcVar6 == '/') && (pcVar6 + 2 < pcVar1)) {
      pcVar6 = pcVar6 + 1;
      iVar3 = (int)*unaff_EBX - (int)pcVar6;
      if (iVar3 - 1U < 0x15) {
        pcVar7 = "CIDFontName";
        local_c = &PTR_s_CIDFontName_00be8a48;
        do {
          if (*pcVar6 == *pcVar7) {
            pcVar4 = pcVar7;
            do {
              cVar2 = *pcVar4;
              pcVar4 = pcVar4 + 1;
            } while (cVar2 != '\0');
            if (iVar3 == (int)pcVar4 - (int)(pcVar7 + 1)) {
              iVar5 = 1;
              if (1 < iVar3) {
                pcVar4 = pcVar6;
                while (pcVar4 = pcVar4 + 1, *pcVar4 == pcVar4[(int)pcVar7 - (int)pcVar6]) {
                  iVar5 = iVar5 + 1;
                  if (iVar3 <= iVar5) goto LAB_008db73d;
                }
                if (iVar5 < iVar3) goto LAB_008db75f;
              }
LAB_008db73d:
              iVar3 = FUN_008db350();
              unaff_EBX[3] = iVar3;
              if (iVar3 != 0) {
                return iVar3;
              }
              goto LAB_008db751;
            }
          }
LAB_008db75f:
          pcVar7 = local_c[9];
          local_c = local_c + 9;
        } while (pcVar7 != (char *)0x0);
        in_ECX = (char *)*unaff_EBX;
        goto LAB_008db650;
      }
    }
LAB_008db751:
    in_ECX = (char *)*unaff_EBX;
  } while( true );
}

