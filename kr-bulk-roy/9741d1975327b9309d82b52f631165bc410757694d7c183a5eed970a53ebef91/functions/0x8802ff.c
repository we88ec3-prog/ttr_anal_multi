
/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */
/* Library Function - Single Match
    protected: virtual class std::istreambuf_iterator<char,struct std::char_traits<char> >
   __thiscall std::num_get<char,class std::istreambuf_iterator<char,struct std::char_traits<char> >
   >::do_get(class std::istreambuf_iterator<char,struct std::char_traits<char> >,class
   std::istreambuf_iterator<char,struct std::char_traits<char> >,class std::ios_base &,int &,bool
   &)const 
   
   Library: Visual Studio 2010 Release */

void __thiscall
std::num_get<char,std::istreambuf_iterator<char,std::char_traits<char>_>_>::do_get
          (undefined4 param_1,undefined4 *param_2,undefined4 param_3,undefined4 param_4,
          undefined4 param_5,undefined4 param_6,int param_7,uint *param_8,undefined4 param_9)

{
  bool bVar1;
  undefined4 uVar2;
  char ***pppcVar3;
  int iVar4;
  uint uVar5;
  num_get<char,std::istreambuf_iterator<char,std::char_traits<char>_>_> *this;
  istreambuf_iterator<char,std::char_traits<char>_> *local_70;
  undefined4 local_6c;
  char *local_68;
  undefined4 *local_64;
  undefined1 local_60 [4];
  int local_5c;
  uint *local_58;
  uint local_54;
  char **local_50 [4];
  undefined4 local_40;
  uint local_3c;
  istreambuf_iterator<char,std::char_traits<char>_> local_34 [4];
  undefined1 local_30 [40];
  undefined4 local_8;
  undefined4 uStack_4;
  
  iVar4 = param_7;
  uStack_4 = 0x60;
  local_8 = 0x88030b;
  local_64 = param_2;
  local_58 = param_8;
  local_6c = param_9;
  local_54 = 0xffffffff;
  if ((*(uint *)(param_7 + 0x14) & 0x4000) == 0) {
    local_5c = 0;
    FUN_004318d0(local_60);
    this = (num_get<char,std::istreambuf_iterator<char,std::char_traits<char>_>_> *)&local_5c;
    local_8 = 4;
    iVar4 = _Getifld(this,local_68,local_34,
                     (istreambuf_iterator<char,std::char_traits<char>_> *)&param_3,(int)&param_5,
                     *(locale **)(iVar4 + 0x14));
    uVar5 = __Stoulx(local_34,&local_70,iVar4,this);
    local_8 = 0xffffffff;
    FUN_004327c0();
    if (((local_70 != local_34) && (local_5c == 0)) && (uVar5 < 2)) {
      local_54 = uVar5;
    }
  }
  else {
    uVar2 = FUN_004318d0(&local_54);
    local_8 = 0;
    FUN_006efcf0(uVar2);
    local_8 = 0xffffffff;
    FUN_004327c0();
    local_3c = 0xf;
    local_40 = 0;
    local_50[0] = (char **)((uint)local_50[0] & 0xffffff00);
    FUN_0046e1b0(1,0);
    local_8 = 1;
    uVar2 = FUN_006ef8b0(local_30);
    local_8._0_1_ = 2;
    FUN_00401ed0(uVar2,0,0xffffffff);
    local_8._0_1_ = 1;
    FUN_00402f30(1,0);
    FUN_00429630(1,0);
    uVar2 = FUN_006ef8d0(local_30);
    local_8._0_1_ = 3;
    FUN_00401ed0(uVar2,0,0xffffffff);
    local_8 = CONCAT31(local_8._1_3_,1);
    FUN_00402f30(1,0);
    pppcVar3 = (char ***)local_50[0];
    if (local_3c < 0x10) {
      pppcVar3 = local_50;
    }
    local_54 = _Getloctxt<char,std::istreambuf_iterator<char,std::char_traits<char>_>_>
                         ((istreambuf_iterator<char,std::char_traits<char>_> *)&param_3,
                          (istreambuf_iterator<char,std::char_traits<char>_> *)&param_5,2,
                          (char *)pppcVar3);
    local_8 = 0xffffffff;
    FUN_00402f30(1,0);
  }
  bVar1 = istreambuf_iterator<char,std::char_traits<char>_>::equal
                    ((istreambuf_iterator<char,std::char_traits<char>_> *)&param_3,
                     (istreambuf_iterator<char,struct_std::char_traits<char>_> *)&param_5);
  if (bVar1) {
    *local_58 = *local_58 | 1;
  }
  if ((int)local_54 < 0) {
    *local_58 = *local_58 | 2;
  }
  else {
    *(bool *)local_6c = local_54 != 0;
  }
  *local_64 = param_3;
  local_64[1] = param_4;
  FUN_0089dbbc();
  return;
}

