// Copyright (c) 2010-2011, Rasmus Andersson. All rights reserved.
// Use of this source code is governed by a MIT-style license that can be
// found in the LICENSE file.

#ifndef KOD_AST_H_
#define KOD_AST_H_

#include "ASTNode.h"
#include "common.h"

#include <vector>
#include <string>
#include <tr1/memory>

namespace kod {

class AST;
typedef std::tr1::shared_ptr<AST> ASTPtr;

class AST {
 public:
  AST() {}
  ~AST() {}

  const ASTNodePtr &rootNode() const { return rootNode_; }
  bool setRootNode(ASTNodePtr rootNode) {
    // TODO(rsms): using CAS or spinlock
    h_atomic_barrier();
    rootNode_ = rootNode;
  }

 protected:
  ASTNodePtr rootNode_;
};


};  // namespace kod

#endif  // KOD_AST_H_
