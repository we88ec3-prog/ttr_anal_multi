
/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */
/* Library Function - Multiple Matches With Same Base Name
    int __cdecl std::_Getloctxt<char,class std::istreambuf_iterator<unsigned short,struct
   std::char_traits<unsigned short> > >(class std::istreambuf_iterator<unsigned short,struct
   std::char_traits<unsigned short> > &,class std::istreambuf_iterator<unsigned short,struct
   std::char_traits<unsigned short> > &,unsigned int,char const *)
    int __cdecl std::_Getloctxt<char,class std::istreambuf_iterator<wchar_t,struct
   std::char_traits<wchar_t> > >(class std::istreambuf_iterator<wchar_t,struct
   std::char_traits<wchar_t> > &,class std::istreambuf_iterator<wchar_t,struct
   std::char_traits<wchar_t> > &,unsigned int,char const *)
   
   Library: Visual Studio 2010 Release */

void _Getloctxt<>(int param_1,undefined4 param_2,uint param_3,char *param_4)

{
  bool bVar1;
  char cVar2;
  undefined4 ****ppppuVar3;
  undefined1 uVar4;
  char *pcVar6;
  uint uVar7;
  int iVar8;
  uint local_38;
  undefined4 ***local_30 [4];
  undefined4 local_20;
  uint local_1c;
  undefined4 local_8;
  undefined4 uStack_4;
  uint uVar5;
  
  uStack_4 = 0x34;
  local_8 = 0x886152;
  cVar2 = *param_4;
  pcVar6 = param_4;
  while (cVar2 != '\0') {
    if (cVar2 == *param_4) {
      param_3 = param_3 + 1;
    }
    pcVar6 = pcVar6 + 1;
    cVar2 = *pcVar6;
  }
  local_1c = 0xf;
  local_20 = 0;
  local_30[0] = (undefined4 ***)((uint)local_30[0] & 0xffffff00);
  FUN_0046e1b0(param_3,0);
  local_8 = 0;
  local_38 = 1;
  while( true ) {
    uVar7 = 0;
    iVar8 = 0;
    bVar1 = false;
    if (param_3 == 0) break;
    do {
      cVar2 = param_4[iVar8];
      if (cVar2 != '\0') {
        do {
          if (cVar2 == *param_4) break;
          iVar8 = iVar8 + 1;
          cVar2 = param_4[iVar8];
        } while (cVar2 != '\0');
      }
      ppppuVar3 = (undefined4 ****)local_30[0];
      if (local_1c < 0x10) {
        ppppuVar3 = local_30;
      }
      if (*(char *)((int)ppppuVar3 + uVar7) == '\0') {
        iVar8 = iVar8 + local_38;
        if ((param_4[iVar8] == *param_4) || (param_4[iVar8] == '\0')) {
          uVar5 = 0x7f;
          if (local_38 < 0x7f) {
            uVar5 = local_38;
          }
          uVar4 = (undefined1)uVar5;
          ppppuVar3 = (undefined4 ****)local_30[0];
          if (local_1c < 0x10) {
            ppppuVar3 = local_30;
          }
        }
        else {
          cVar2 = equal(param_2);
          if (cVar2 == '\0') {
            if (*(char *)(param_1 + 4) == '\0') {
              Peek();
            }
            if ((int)param_4[iVar8] == (uint)*(ushort *)(param_1 + 6)) {
              bVar1 = true;
              goto LAB_00886267;
            }
          }
          uVar5 = local_38;
          if (0x7e < local_38) {
            uVar5 = 0x7f;
          }
          uVar4 = (undefined1)uVar5;
          ppppuVar3 = (undefined4 ****)local_30[0];
          if (local_1c < 0x10) {
            ppppuVar3 = local_30;
          }
        }
        *(undefined1 *)((int)ppppuVar3 + uVar7) = uVar4;
      }
      else {
        ppppuVar3 = (undefined4 ****)local_30[0];
        if (local_1c < 0x10) {
          ppppuVar3 = local_30;
        }
        iVar8 = iVar8 + *(char *)((int)ppppuVar3 + uVar7);
      }
LAB_00886267:
      uVar7 = uVar7 + 1;
    } while (uVar7 < param_3);
    if ((!bVar1) || (cVar2 = equal(param_2), cVar2 != '\0')) break;
    local_38 = local_38 + 1;
    Inc();
  }
  FUN_00402f30(1,0);
  FUN_0089dbbc();
  return;
}

