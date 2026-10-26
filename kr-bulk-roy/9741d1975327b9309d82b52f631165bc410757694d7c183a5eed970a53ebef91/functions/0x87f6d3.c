
/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */
/* Library Function - Single Match
    int __cdecl std::_Getloctxt<char,class std::istreambuf_iterator<char,struct
   std::char_traits<char> > >(class std::istreambuf_iterator<char,struct std::char_traits<char> >
   &,class std::istreambuf_iterator<char,struct std::char_traits<char> > &,unsigned int,char const
   *)
   
   Library: Visual Studio 2010 Release */

int __cdecl
std::_Getloctxt<char,std::istreambuf_iterator<char,std::char_traits<char>_>_>
          (istreambuf_iterator<char,std::char_traits<char>_> *param_1,
          istreambuf_iterator<char,std::char_traits<char>_> *param_2,uint param_3,char *param_4)

{
  char cVar1;
  bool bVar2;
  bool bVar3;
  undefined4 ****ppppuVar4;
  undefined1 uVar5;
  char *pcVar7;
  uint uVar8;
  int iVar9;
  uint local_38;
  undefined4 ***local_30 [4];
  undefined4 local_20;
  uint local_1c;
  undefined4 local_8;
  undefined4 uStack_4;
  uint uVar6;
  
  uStack_4 = 0x34;
  local_8 = 0x87f6df;
  cVar1 = *param_4;
  pcVar7 = param_4;
  while (cVar1 != '\0') {
    if (cVar1 == *param_4) {
      param_3 = param_3 + 1;
    }
    pcVar7 = pcVar7 + 1;
    cVar1 = *pcVar7;
  }
  local_1c = 0xf;
  local_20 = 0;
  local_30[0] = (undefined4 ***)((uint)local_30[0] & 0xffffff00);
  FUN_0046e1b0(param_3,0);
  local_8 = 0;
  local_38 = 1;
  while( true ) {
    uVar8 = 0;
    iVar9 = 0;
    bVar3 = false;
    if (param_3 == 0) break;
    do {
      cVar1 = param_4[iVar9];
      if (cVar1 != '\0') {
        do {
          if (cVar1 == *param_4) break;
          iVar9 = iVar9 + 1;
          cVar1 = param_4[iVar9];
        } while (cVar1 != '\0');
      }
      ppppuVar4 = (undefined4 ****)local_30[0];
      if (local_1c < 0x10) {
        ppppuVar4 = local_30;
      }
      if (*(char *)((int)ppppuVar4 + uVar8) == '\0') {
        iVar9 = iVar9 + local_38;
        if ((param_4[iVar9] == *param_4) || (param_4[iVar9] == '\0')) {
          uVar6 = 0x7f;
          if (local_38 < 0x7f) {
            uVar6 = local_38;
          }
          uVar5 = (undefined1)uVar6;
          ppppuVar4 = (undefined4 ****)local_30[0];
          if (local_1c < 0x10) {
            ppppuVar4 = local_30;
          }
        }
        else {
          bVar2 = istreambuf_iterator<char,std::char_traits<char>_>::equal
                            (param_1,(istreambuf_iterator<char,struct_std::char_traits<char>_> *)
                                     param_2);
          if (!bVar2) {
            if (param_1[4] == (istreambuf_iterator<char,std::char_traits<char>_>)0x0) {
              istreambuf_iterator<char,std::char_traits<char>_>::_Peek(param_1);
            }
            if (*(istreambuf_iterator<char,std::char_traits<char>_> *)(param_4 + iVar9) ==
                param_1[5]) {
              bVar3 = true;
              goto LAB_0087f7f0;
            }
          }
          uVar6 = local_38;
          if (0x7e < local_38) {
            uVar6 = 0x7f;
          }
          uVar5 = (undefined1)uVar6;
          ppppuVar4 = (undefined4 ****)local_30[0];
          if (local_1c < 0x10) {
            ppppuVar4 = local_30;
          }
        }
        *(undefined1 *)((int)ppppuVar4 + uVar8) = uVar5;
      }
      else {
        ppppuVar4 = (undefined4 ****)local_30[0];
        if (local_1c < 0x10) {
          ppppuVar4 = local_30;
        }
        iVar9 = iVar9 + *(char *)((int)ppppuVar4 + uVar8);
      }
LAB_0087f7f0:
      uVar8 = uVar8 + 1;
    } while (uVar8 < param_3);
    if ((!bVar3) ||
       (bVar3 = istreambuf_iterator<char,std::char_traits<char>_>::equal
                          (param_1,(istreambuf_iterator<char,struct_std::char_traits<char>_> *)
                                   param_2), bVar3)) break;
    local_38 = local_38 + 1;
    istreambuf_iterator<char,std::char_traits<char>_>::_Inc(param_1);
  }
  FUN_00402f30(1,0);
  iVar9 = FUN_0089dbbc();
  return iVar9;
}

